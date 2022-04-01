from File_functions import write_automobiles_into_file, display_file_information, write_new_file_of_automobile

path_automobile_list = "automobiles\\List of automobiles.txt"
new_path_automobile_list = "automobiles\\New automobiles.txt"
write_automobiles_into_file(path_automobile_list)
print("There is information in file:\n")
display_file_information(path_automobile_list)
print("-----------------------------------------------------\n")
write_new_file_of_automobile(path_automobile_list, new_path_automobile_list)
print("There is a list of automobiles that have been sold within 2 months after production:")
display_file_information(new_path_automobile_list)