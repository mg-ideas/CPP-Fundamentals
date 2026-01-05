output="../htmls"
mkdir -p "$output"
cd notebooks || exit 1
for file in *.ipynb 
    do echo "Converting $file to HTML..." 
    jupyter nbconvert --to html "$file" --output-dir "$output" 
done
count=$(ls -1q "$output"/*.html | wc -l)
echo "Converted $count notebooks to HTML format in $output folder."
