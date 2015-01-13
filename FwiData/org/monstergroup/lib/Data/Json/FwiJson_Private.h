//  Project name: FwiData
//  File name   : FwiJson_Private.h
//
//  Author      : Phuc, Tran Huu
//  Created date: 9/23/12
//  Version     : 1.20
//  --------------------------------------------------------------
//  Copyright (C) 2012, 2014 Monster Group.
//  All Rights Reserved.
//  --------------------------------------------------------------
//
//  Permission is hereby granted, free of charge, to any person obtaining  a  copy
//  of this software and associated documentation files (the "Software"), to  deal
//  in the Software without restriction, including without limitation  the  rights
//  to use, copy, modify, merge,  publish,  distribute,  sublicense,  and/or  sell
//  copies of the Software,  and  to  permit  persons  to  whom  the  Software  is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF  ANY  KIND,  EXPRESS  OR
//  IMPLIED, INCLUDING BUT NOT  LIMITED  TO  THE  WARRANTIES  OF  MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO  EVENT  SHALL  THE
//  AUTHORS OR COPYRIGHT HOLDERS  BE  LIABLE  FOR  ANY  CLAIM,  DAMAGES  OR  OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN  THE
//  SOFTWARE.
//
//
//  Disclaimer
//  __________
//  Although reasonable care has been taken to  ensure  the  correctness  of  this
//  software, this software should never be used in any application without proper
//  testing. Monster Group  disclaim  all  liability  and  responsibility  to  any
//  person or entity with respect to any loss or damage caused, or alleged  to  be
//  caused, directly or indirectly, by the use of this software.

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, FwiJsonValue) {
	kJson_Null    = 0x00,
	kJson_Boolean = 0x01,
	kJson_Number  = 0x02,
	kJson_String  = 0x03,
    // Structure types
	kJson_Array   = 0x10,
	kJson_Object  = 0x11
};


@interface FwiJson () {
}

@property (nonatomic, readonly) FwiJsonValue jsonType;

@property (nonatomic, retain) NSMutableArray *array;
@property (nonatomic, retain) NSMutableDictionary *dictionary;


/** Convert NSObject to JSON object. */
+ (__autoreleasing FwiJson *)_JsonFromObject:(id)object;
/** Convert JSON object to NSObject. */
+ (__autoreleasing id)_objectFromJson:(FwiJson *)json;

/** Create array from dynamic array. */
+ (void)_array:(NSMutableArray *)array arg:(id)arg args:(va_list)args;
/** Create dictionary from dynamic array. */
+ (void)_dictionary:(NSMutableDictionary *)dictionary arg:(id)arg args:(va_list)args;

@end


@interface FwiJson (FwiJsonCreation_Private)

// Class's constructors
- (id)initWithJsonType:(FwiJsonValue)jsonType;

@end