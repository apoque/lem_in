deployDir=./maps_gen
if [ ! -d "$deployDir" ]; then
	   echo "making dir $deployDir"
	      mkdir -p "$deployDir"
fi

for m in {1..200};do
	f=$(((RANDOM % 100)+1)) 
	r=$(((RANDOM % 1000)+500)) 
	./lem-in_gen $f $r > $deployDir/test_$f-$r.txt
done;

for map in ./maps_gen;do
	../../lem_in < $map >> def_file.csv
done;
