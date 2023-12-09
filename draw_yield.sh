#!/bin/bash

threads=4
start_time=$(date +%s)
waitForMe (){
    while : 
    do 
	activth=$(ps aux | grep "[p]rtdirc\|draw_yield.C" | grep -v "grep" | wc -l)
	printf "\r$statusline [$activth] ---- [$(($(date +%s) - start_time)) s] "
	if [ "$activth" -lt "$1" ]; then 
	    break  
	fi
	sleep 1
    done

}

for i in {1..50}; do   
            #../build/prtdirc -study 403 -a 140 -e 1000 -t1 $i -b 1 -x pi+ -o hits_$i.root &
            root -b -q -l draw_yield.C"(\"hits_$i.root\")" &
            waitForMe $threads
           
done    
waitForMe 1

#hadd -f all_roughness.root roughness_*.root
#root -b -q -l graph.C"(\"all_roughness.root\")"
echo "Done"
#90,140