/*
//File: FilterCommand.hpp
// Author: Abril Sifuentes
// Date: 11/19/2025
// functions FilterCommand.hpp 
*/
#pragma once
#include <string>
#include <memory>
#include <vector>
#include "files/image/ImageFile.hpp"
#include "filters/ImageFilter.hpp"
#include "history/Command.hpp"




class FilterCommand : public Command {
	private:
		/*
		1.  A reference to the `ImageFile` being modified (NOT A COPY).
		2.  A `std::shared_ptr<ImageFilter>` to store the _actual_ filter being applied.
		3.  Two 2D `Pixel` vectors to store the "before" and "after" states
		*/
		ImageFile& image;
		const std::shared_ptr<ImageFilter> applied_filter_;  // put here
		std::vector<std::vector<Pixel>> before;
		std::vector<std::vector<Pixel>> after;


	public: 
		FilterCommand(ImageFile & imageFile,  const ImageFilter & filter);
		void execute()override;
		void undo()override;
		void redo() override;
		ImageFile& getModifiedImage()const;
		std::shared_ptr<ImageFilter>getAppliedFilter()const;
		std::string toString() const override;

};
