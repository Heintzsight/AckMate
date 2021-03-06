// Copyright (c) 2010 Trevor Squires. All Rights Reserved.
// See License.txt for full license.

#import <Cocoa/Cocoa.h>

@class JPAckResultRep;
@class JPAckWindowController;
@class JPAckResultTableView;

@interface JPAckResultSource : NSObject {
  NSUInteger matchedFiles;
  NSUInteger matchedLines;
  NSMutableArray* resultRows;

  NSDictionary* headingAttributes;
  NSDictionary* bodyAttributes;
  NSDictionary* bodyNowrapAttributes;
  NSDictionary* bodyHighlightAttributes;

  IBOutlet JPAckResultTableView* resultView;
  IBOutlet JPAckWindowController* windowController;

  JPAckResultRep* currentResultFileRep;

  NSString* resultStats;
  BOOL searchingSelection;
  NSString* searchRoot;
  BOOL alternateRow;
  
  NSString* longestLineNumber;

  CGFloat headerHeight;
  CGFloat contextBreakHeight;
}

@property(nonatomic, copy) NSString* searchRoot;
@property(nonatomic, readonly) NSUInteger matchedFiles;
@property(nonatomic, readonly) NSUInteger matchedLines;
@property(nonatomic, copy, readonly) NSString* resultStats;

- (void)clearContents;
- (void)updateStats;
- (void)searchingFor:(NSString*)term inRoot:(NSString*)searchRoot inFolder:(NSString*)searchFolder;
- (void)parsedError:(NSString*)errorString;
- (void)parsedFilename:(NSString*)filename;
- (void)parsedContextLine:(NSString*)lineNumber content:(NSString*)content;
- (void)parsedMatchLine:(NSString*)lineNumber ranges:(NSArray*)ranges content:(NSString*)content;
- (void)parsedContextBreak;

- (BOOL)tableView:(NSTableView *)tableView isStickyRow:(NSInteger)row;

@end
