# Photon yield
• After running the Geant4 simulation, where the codes used for simulating the DIRC detector can be found at the link: https://github.com/rdom/prtdirc.<br>
• To run the simulation for different surface roughness values, the range of surface
roughness in the shell script draw yield.sh can be adjusted. Once the simulations are complete, the line that executes the draw yield.C macro can be uncommented.<br>
• The draw yield.C. macro will be used to create a root file containing the roughness, mean value of the number of generated photons, and mean error. Then, for
each angle, a TGraphErrors of the number of photons as a function of the wavelength will be drawn using the graph.C macro. A root file containing the graph
will be created for each angle. However, the name of the file should be adjusted
only. The graph combined.C macro will be employed to merge these graphs
into one. <br>
