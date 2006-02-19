/*****************************************************************************
 * interaction.h: Mac OS X interaction dialogs
 *****************************************************************************
 * Copyright (C) 2001-2005 the VideoLAN team
 * $Id: vout.h 13803 2005-12-18 18:54:28Z bigben $
 *
 * Authors: Derk-Jan Hartman <hartman at videolan dot org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include <vlc/vlc.h>
#include <vlc_interaction.h>
#include <Cocoa/Cocoa.h>

/*****************************************************************************
 * VLCInteraction interface
 *****************************************************************************/
@interface VLCInteraction : NSObject
{
    interaction_dialog_t    *p_dialog;
    intf_thread_t * p_intf;
}

-(id)initDialog: (interaction_dialog_t *)_p_dialog;
-(void)runDialog;
-(void)updateDialog;
-(void)hideDialog;
-(void)destroyDialog;

@end

/*****************************************************************************
 * VLCInteractionList interface
 *****************************************************************************/
@interface VLCInteractionList : NSObject
{
    NSMutableArray *o_interaction_list;
}

-(void)newInteractionEvent: (NSNotification *)o_notification;
-(void)addInteraction: (interaction_dialog_t *)p_dialog;
-(void)removeInteraction: (VLCInteraction *)p_interaction;

@end
