chmod a+rwx ai_door_management_module.sh
mv door_management_fi door_management_files
mkdir door_logs
mkdir door_map 
mkdir door_configuration
mv *.conf ~/Desktop/T01D01-0/src/door_configuration
mv *.log ~/Desktop/T01D01-0/src/door_logs
mv door_map_1.1 ~/Desktop/T01D01-0/src/door_map
chmod a+rwx ai_door_control.sh
