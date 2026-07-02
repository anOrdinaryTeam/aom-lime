#ifdef HX_MACOS
#import <Cocoa/Cocoa.h>
#else
#import <UIKit/UIKit.h>
#endif

#include <system/Locale.h>


namespace lime {


	float Display::GetDPI () {

		#if !__has_feature(objc_arc)
		NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
		#endif

		NSString* locale = [[NSLocale currentLocale] localeIdentifier];
		std::string* result = 0;

		if (locale) {

			const char* ptr = [locale UTF8String];
			result = new std::string (ptr);

		}

		#if !__has_feature(objc_arc)
		[pool drain];
		#endif

		return result;

	}


}