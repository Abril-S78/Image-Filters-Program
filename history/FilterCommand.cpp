/*
//File: FilterCommand.cpp
// Author: Abril Sifuentes
// Date: 11/19/2025
// functions implement invertfilter
*/
#include"FilterCommand.hpp" 
#include<sstream>



/**
 * @param imageFile The ImageFile object to be modified as a (non-const) reference
 * @param filter The filter to be applied (e.g. InvertFilter) as a const reference.
 */
FilterCommand::FilterCommand(ImageFile& imageFile, const ImageFilter& filter)
    : image(imageFile), applied_filter_(filter.clone()), before(),after()
{}

	


/**
 * @brief Executes the filter application.
 * @post
 * 1. The pixel data of the image's state *before* filtering is stored.
 * 2. The filter is applied to the image passed in the constructor (and modifying that original image object directly)
 * 3. (depending on implementation) The pixel data of the image's *after* filtering is stored.
 */
void FilterCommand::execute(){
	before = image.getPixels();//stores before
	applied_filter_->apply(image);
	after = image.getPixels();//stores after 
}
/**
 * @brief Undoes the filter application.
 * @post The modified Image's pixels are restored to the pixel data before the filter was applied.
 */
void FilterCommand::undo(){
	image.setPixels(before);
}
/**
 * @brief Re-applies the filter application.
 * @post The modified Image's pixels are restored the pixel data after the filter was applied.
 */
void FilterCommand::redo(){
	image.setPixels(after);
}
/**
 * @brief Gets the image file modified by this command.
 * @return The ImageFile object.
 */
ImageFile & FilterCommand::getModifiedImage()const{
	return image;
}
/**
 * @brief Gets the filter that was applied by this command.
 * @return A shared_ptr to the ImageFilter.
 */
std::shared_ptr<ImageFilter> FilterCommand::getAppliedFilter()const{
	return applied_filter_;
}
/**
 * @brief Generates a string representation of the command.
 * @return A string in the format: "<Filter Name> --> <Filename>"
 */
std::string FilterCommand::toString()const{
	std::ostringstream oss;
	oss << applied_filter_->name() << " --> " << image.getFilename();
	return oss.str();
}