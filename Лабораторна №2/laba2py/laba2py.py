from File_functions import write_automobiles_into_file, display_file_information

path_automobile_list = "automobiles\\List of automobiles.txt"
new_path_automobile_list = "automobiles\\New automobiles.txt"
write_automobiles_into_file(path_automobile_list)
print("There is information in file:\n")
display_file_information(path_automobile_list)
print("-----------------------------------------------------\n")