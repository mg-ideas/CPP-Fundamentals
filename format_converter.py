"""Program converts all Jupyter Notebook (*.ipynb) files into given format
"""

import sys
import os
import subprocess
import argparse
import shutil
from typing import Any
from pathlib import Path


def convert(input_file: Path, output_file: Path, oformat='pdf') -> Any:
    """Convert file format

    Args:
        input_file (Path): input file
        output_file (Path): output file
        oformat (str, optional): Format to convert to. Defaults to 'pdf'.

    Returns:
        stderr
    """
    print(f'{input_file=}, {output_file=}, {oformat=}', file=sys.stderr)
    out = subprocess.Popen(
        ['jupyter', 'nbconvert', '--to', oformat,
         input_file, '--output', output_file])
    _, stderr = out.communicate()
    return stderr


def convert_to_latex(files: list[str], input_dir: Path, output_dir: Path) -> None:
    """ Function to convert list of files in input_dir to Latex.

    Args:
        files (list[str]): list of files
        input_dir (str): directory that contains the inout files
        output_dir (str): output directory to save Latex file to
    """
    errors: list[Any] = []
    if os.path.exists(output_dir):
        shutil.rmtree(output_dir)
    assets_dir = input_dir / 'assets'
    shutil.copytree(assets_dir, output_dir / 'assets', dirs_exist_ok=True)
    os.makedirs(output_dir, exist_ok=True)
    for inf in files:
        output_file = output_dir / inf.replace('.ipynb', '.tex')

        error = convert(input_dir / inf, output_file, 'latex')
        if error:
            errors.append(error)
    print(errors, file=sys.stderr)


def convert_to_pdfs(input_dir: Path, output_dir: Path) -> None:
    """Function to convert ipynb into pdfs

    Args:
        output_dir (str): output folder
    """
    if os.path.exists(output_dir):
        shutil.rmtree(output_dir)
    os.mkdir(output_dir)
    files = [f for f in os.listdir(input_dir) if f.endswith('.tex')]
    file_ext = ['*.aux', '*.log', '*.out']
    for f in files:
        in_file = input_dir / f
        with open(in_file, 'r', encoding='utf-8') as fin:
            latex = fin.read()
            latex = latex.replace('.ipynb', '.pdf')
        with open(out_path, 'w', encoding='utf-8') as fout:
            fout.write(latex)

        cmd = f'pdflatex -output-directory={output_dir} {out_path}'
        print(cmd)
        process = subprocess.run(cmd.split())
        # output, error = process.communicate()
        # print(output)
        subprocess.run(['clear'])

    for ext in file_ext:
        cmd = 'rm ' + str(output_dir / ext)
        print(cmd)
        process = subprocess.run(cmd.split())
        # process.communicate()

    print(f'all done! see {output_dir} folder...')


def main():
    parser = argparse.ArgumentParser(description="Notebook converter")
    parser.add_argument('-id', '--inputDir', default=".",
                        help="Input Folder; default is current folder the script is running from")
    parser.add_argument('-f', '--format', default="pdf",
                        help="conversion type; default is pdf other options: pdf, latex, html, webpdf, slides")

    args = vars(parser.parse_args())  # convert Namespace to dict()
    # print(args)
    # print(os.listdir(args['inputFolder']))
    input_path = Path(args['inputDir'])
    if not input_path.exists() or not input_path.is_dir():
        print(
            f'Input folder {args["inputDir"]} does not exist or is not a directory.')
        sys.exit(1)
    output_path = input_path / "pdfs"
    files = [f for f in os.listdir(input_path) if f.endswith('.ipynb')]
    errors = []
    format_type = args['format']
    if format_type == 'latex':
        convert_to_latex(files, input_path, output_path)
    elif format_type == 'pdf':
        convert_to_latex(files, input_path,  Path("latex"))
        # convert_to_pdfs(output_path, output_path)

    print(f'Total {len(files)} notebooks found in {args["inputDir"]} folder.')
    print(f'Total {len(errors)} errors:')
    print('\n'.join(errors))


if __name__ == "__main__":
    main()
