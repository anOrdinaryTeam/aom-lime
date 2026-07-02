#ifdef HX_MACOS
#import <Cocoa/Cocoa.h>
#else
#import <UIKit/UIKit.h>
#endif

#include <system/Locale.h>


namespace lime {


	std::string* Locale::GetSystemLocale () {

		// NSAutoreleasePool is unavailable under ARC (Xcode 26 compiles .mm with ARC by default).
		// __has_feature(objc_arc) is the correct probe -- the old OBJC_ARC guard was never defined.
		#if !__has_feature(objc_arc)
		NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
		#endif

		NSString* localeLanguage = [[NSLocale preferredLanguages] firstObject];
		if (localeLanguage == nil) localeLanguage = @"en";

		NSString* localeRegion = nil;
		NSLocale* currentLocale = [NSLocale autoupdatingCurrentLocale];
		if (currentLocale == nil || ![currentLocale respondsToSelector:@selector(countryCode)]) {
			localeRegion = @"";
		} else {
			localeRegion = [currentLocale countryCode];
		}

		NSString* locale = localeLanguage;
		if (localeRegion != nil)
		{
			locale = [[localeLanguage stringByAppendingString:@"_"] stringByAppendingString:localeRegion];
		}

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