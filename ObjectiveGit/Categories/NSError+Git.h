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
	nomemory = GITERR_NOMEMORY,
	os = GITERR_OS,
	invalid = GITERR_INVALID,
	reference = GITERR_REFERENCE,
	zlib = GITERR_ZLIB,
	repository = GITERR_REPOSITORY,
	config = GITERR_CONFIG,
	regex = GITERR_REGEX,
	odb = GITERR_ODB,
	indexError = GITERR_INDEX,
	object = GITERR_OBJECT,
	net = GITERR_NET,
	tag = GITERR_TAG,
	tree = GITERR_TREE,
	indexer = GITERR_INDEXER,
	ssl = GITERR_SSL,
	submodule = GITERR_SUBMODULE,
	thread = GITERR_THREAD,
	stash = GITERR_STASH,
	checkout = GITERR_CHECKOUT,
	fetchhead = GITERR_FETCHHEAD,
	merge = GITERR_MERGE,
	ssh = GITERR_SSH,
	filterError = GITERR_FILTER,
	revert = GITERR_REVERT,
	callback = GITERR_CALLBACK,
	cherrypick = GITERR_CHERRYPICK,
	describe = GITERR_DESCRIBE,
	rebase = GITERR_REBASE,
	filesystem = GITERR_FILESYSTEM,
	patch = GITERR_PATCH,
	worktree = GITERR_WORKTREE,
	sha = GITERR_SHA1,
	
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
