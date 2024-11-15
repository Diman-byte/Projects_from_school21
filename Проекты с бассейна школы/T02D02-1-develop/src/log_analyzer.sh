cd ..

dir=$1


if [[ -f $dir ]]; then
	a=($(wc -l $dir))
	names=$(awk ' /src/{print $1}' $dir | uniq)
	b=$(find $names -type f | wc -l)
	echo "$a $b"
else
	echo "Error"
fi
