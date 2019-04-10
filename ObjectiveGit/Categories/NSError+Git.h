//
//  NSError+Git.h
//  ObjectiveGitFramework
//
//  Created by Timothy Clem on 2/17/11.
//
//  The MIT License
//
//  Copyright (c) 2011 Tim Clem
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import "git2/errors.h"
#import "GTReference.h"

/// The error domain used by Objective-Git
extern NSErrorDomain const GTGitErrorDomain;
typedef NS_ERROR_ENUM(GTGitErrorDomain, GTGitError) {
	nomemory = GIT_ERROR_NOMEMORY,
	os = GIT_ERROR_OS,
	invalid = GIT_ERROR_INVALID,
	reference = GIT_ERROR_REFERENCE,
	zlib = GIT_ERROR_ZLIB,
	repository = GIT_ERROR_REPOSITORY,
	config = GIT_ERROR_CONFIG,
	regex = GIT_ERROR_REGEX,
	odb = GIT_ERROR_ODB,
	indexError = GIT_ERROR_INDEX,
	object = GIT_ERROR_OBJECT,
	net = GIT_ERROR_NET,
	tag = GIT_ERROR_TAG,
	tree = GIT_ERROR_TREE,
	indexer = GIT_ERROR_INDEXER,
	ssl = GIT_ERROR_SSL,
	submodule = GIT_ERROR_SUBMODULE,
	thread = GIT_ERROR_THREAD,
	stash = GIT_ERROR_STASH,
	checkout = GIT_ERROR_CHECKOUT,
	fetchhead = GIT_ERROR_FETCHHEAD,
	merge = GIT_ERROR_MERGE,
	ssh = GIT_ERROR_SSH,
	filterError = GIT_ERROR_FILTER,
	revert = GIT_ERROR_REVERT,
	callback = GIT_ERROR_CALLBACK,
	cherrypick = GIT_ERROR_CHERRYPICK,
	describe = GIT_ERROR_DESCRIBE,
	rebase = GIT_ERROR_REBASE,
	filesystem = GIT_ERROR_FILESYSTEM,
	patch = GIT_ERROR_PATCH,
	worktree = GIT_ERROR_WORKTREE,
	sha = GIT_ERROR_SHA1,
	
	error = GIT_ERROR,
	enotfound = GIT_ENOTFOUND,
	eexists = GIT_EEXISTS,
	eambiguous = GIT_EAMBIGUOUS,
	ebufs = GIT_EBUFS,
	
	euser = GIT_EUSER,
	
	ebarerepo = GIT_EBAREREPO,
	eunbornbranch = GIT_EUNBORNBRANCH,
	eunmerged = GIT_EUNMERGED,
	enonfastforward = GIT_ENONFASTFORWARD,
	einvalidspec = GIT_EINVALIDSPEC,
	econflict = GIT_ECONFLICT,
	elocked = GIT_ELOCKED,
	emodified = GIT_EMODIFIED,
	eauth = GIT_EAUTH,
	ecertificate = GIT_ECERTIFICATE,
	eapplied = GIT_EAPPLIED,
	epeel = GIT_EPEEL,
	eeof = GIT_EEOF,
	einvalid = GIT_EINVALID,
	euncommitted = GIT_EUNCOMMITTED,
	edirectory = GIT_EDIRECTORY,
	emergeconflict = GIT_EMERGECONFLICT,
	
	passthrough = GIT_PASSTHROUGH,
	iterover = GIT_ITEROVER,
	retry = GIT_RETRY,
	emismatch = GIT_EMISMATCH,
	
	invalidReference = GTReferenceErrorCodeInvalidReference

};

/// Error userinfo keys
extern NSString * const GTGitErrorOID;

@interface NSError (Git)

/// Describes the given libgit2 error code, using any message provided by
/// libgit2 or the OS.
///
/// code - The error code returned from libgit2.
///
/// Returns a non-nil NSError.
+ (NSError *)git_errorFor:(int)code;

/// Describes the given libgit2 error code, using `desc` as the error's
/// description, and a failure reason from `reason` and the arguments that
/// follow.
///
/// The created error will also have an `NSUnderlyingErrorKey` that contains the
/// result of +git_errorFor: on the same error code.
///
/// code   - The error code returned from libgit2.
/// desc   - The description to use in the created NSError. This may be nil.
/// reason - A format string to use for the created NSError's failure reason.
///          This may be nil.
/// ...    - Format arguments to insert into `reason`.
///
/// Returns a non-nil NSError.
+ (NSError *)git_errorFor:(int)code description:(NSString *)desc failureReason:(NSString *)reason, ... NS_FORMAT_FUNCTION(3, 4);

/// Describes the given libgit2 error code, using `desc` and the arguments that
/// follow as the error's description.
///
/// The created error will also have an `NSUnderlyingErrorKey` that contains the
/// result of +git_errorFor: on the same error code.
///
/// code - The error code returned from libgit2.
/// desc - A format string to use for the created NSError's description. This may be nil.
/// ...  - Format arguments to insert into `desc`.
///
/// Returns a non-nil NSError.
+ (NSError *)git_errorFor:(int)code description:(NSString *)desc, ... NS_FORMAT_FUNCTION(2, 3);


/// Describes the given libgit2 error code, using `desc` as the error's
/// description, and a failure reason from `reason` and the arguments that
/// follow.
///
/// The created error will also have an `NSUnderlyingErrorKey` that contains the
/// result of +git_errorFor: on the same error code.
///
/// code     - The error code returned from libgit2.
/// desc     - The description to use in the created NSError. This may be nil.
/// userInfo - A dictionary of additional values to insert in the NSError userInfo.
///            This may be nil.
/// reason   - A format string to use for the created NSError's failure reason.
///            This may be nil.
/// ...      - Format arguments to insert into `reason`.
///
/// Returns a non-nil NSError.
+ (NSError *)git_errorFor:(int)code description:(NSString *)desc userInfo:(NSDictionary *)userInfo failureReason:(NSString *)reason, ... NS_FORMAT_FUNCTION(4, 5);
@end
