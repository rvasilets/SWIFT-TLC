/*
**  %Z% %I% %W% %G% %U%
**
**  ZZ_Copyright_BEGIN
**
**
**  Licensed Materials - Property of IBM
**
**  IBM Linear Tape File System Single Drive Edition Version 1.3.0.2 for Linux and Mac OS X
**
**  Copyright IBM Corp. 2010, 2013
**
**  This file is part of the IBM Linear Tape File System Single Drive Edition for Linux and Mac OS X
**  (formally known as IBM Linear Tape File System)
**
**  The IBM Linear Tape File System Single Drive Edition for Linux and Mac OS X is free software;
**  you can redistribute it and/or modify it under the terms of the GNU Lesser
**  General Public License as published by the Free Software Foundation,
**  version 2.1 of the License.
**
**  The IBM Linear Tape File System Single Drive Edition for Linux and Mac OS X is distributed in the
**  hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
**  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
**  See the GNU Lesser General Public License for more details.
**
**  You should have received a copy of the GNU Lesser General Public
**  License along with this library; if not, write to the Free Software
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
**  or download the license from <http://www.gnu.org/licenses/>.
**
**
**  ZZ_Copyright_END
**
*************************************************************************************
**
** COMPONENT NAME:  IBM Linear Tape File System
**
** FILE NAME:       iosched_ops.h
**
** DESCRIPTION:     Defines operations that must be supported by the I/O schedulers.
**
** AUTHOR:          Lucas C. Villa Real
**                  IBM Almaden Research Center
**                  lucasvr@us.ibm.com
**
*************************************************************************************
*/
#ifndef __iosched_ops_h
#define __iosched_ops_h

#include "ltfs.h"

/**
 * iosched_ops structure. 
 * Defines operations that must be supported by the I/O schedulers.
 */
struct iosched_ops {
	void    *(*init)(struct ltfs_volume *vol);
	int      (*destroy)(void *iosched_handle);
	int      (*open)(const char *path, bool open_write, struct dentry **dentry,
					 void *iosched_handle);
	int      (*close)(struct dentry *d, bool flush, void *iosched_handle);
	ssize_t  (*read)(struct dentry *d, char *buf, size_t size, off_t offset, void *iosched_handle);
	ssize_t  (*write)(struct dentry *d, const char *buf, size_t size, off_t offset,
					  bool isupdatetime, void *iosched_handle);
	int      (*flush)(struct dentry *d, bool closeflag, void *iosched_handle);
	int      (*truncate)(struct dentry *d, off_t length, void *iosched_handle);
	uint64_t (*get_filesize)(struct dentry *d, void *iosched_handle);
	int      (*update_data_placement)(struct dentry *d, void *iosched_handle);
};

struct iosched_ops *iosched_get_ops(void);
const char *iosched_get_message_bundle_name(void **message_data);

#endif /* __iosched_ops_h */
