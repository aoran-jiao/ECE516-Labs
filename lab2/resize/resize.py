from PIL import Image
import numpy as np

def resize_image(input_image_path, base_height=72):
    # Open the input image
    img = Image.open(input_image_path)
    
    # Calculate the new height maintaining the aspect ratio
    h_percent = (base_height / float(img.size[1]))
    w_size = int((float(img.size[0]) * float(h_percent)))
    
    # Resize the image
    img = img.resize((w_size, base_height), Image.Resampling.LANCZOS)

    # Rotate the image 90 degrees clockwise
    img = img.rotate(-90, expand=True)

    #Convert the image to a numpy array
    img = img.convert('RGB')
    img_array = np.asarray(img)
    
    # Return the image as a numpy array
    return img_array

def save_array_to_text(img_array, output_file_path):
    with open(output_file_path, 'w') as file:
        # Start of the entire image array
        file.write("{\n")
        for row_idx, row in enumerate(img_array):
            # Format each pixel's RGB values with curly braces
            row_str = ', '.join([f"{{{pixel[0]}, {pixel[1]}, {pixel[2]}}}" for pixel in row])
            # Enclose each row in curly braces and separate rows with commas, except for the last row
            if row_idx < len(img_array) - 1:
                file.write(f"{{ {row_str} }},\n")
            else:
                file.write(f"{{ {row_str} }}\n")
        # End of the entire image array
        file.write("}")

# Example usage
input_image_path = './RT-2-6-2024.png'  # Path to your input image
output_file_path = './RT-2-6-2024.txt'  # Path for the output text file

# Process the image and get the 3D array
img_array = resize_image(input_image_path)

# Save the array to the text file
save_array_to_text(img_array, output_file_path)

print(f"Saved the image array to {output_file_path}")
