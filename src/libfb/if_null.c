/*                       I F _ N U L L . C
 * BRL-CAD
 *
 * Copyright (c) 1989-2016 United States Government as represented by
 * the U.S. Army Research Laboratory.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * version 2.1 as published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this file; see the file named COPYING for more
 * information.
 */
/** @addtogroup libfb */
/** @{ */
/** @file if_null.c
 *
 * A Null Frame Buffer.
 * Useful for benchmarking or debugging.
 *
 */
/** @} */

#include "common.h"

#include <stdlib.h>
#include <stdio.h>

#include "bu/log.h"
#include "fb_private.h"
#include "fb.h"


HIDDEN int
_fb_null_open(fb *ifp, const char *UNUSED(file), int width, int height)
{
    FB_CK_FB(ifp);

    if (width > 0)
	ifp->if_width = width;
    if (height > 0)
	ifp->if_height = height;

    return 0;
}

HIDDEN struct fb_platform_specific *
_fb_null_get_fbps(uint32_t UNUSED(magic))
{
        return NULL;
}


HIDDEN void
_fb_null_put_fbps(struct fb_platform_specific *UNUSED(fbps))
{
        return;
}

HIDDEN int
_fb_null_open_existing(fb *UNUSED(ifp), int UNUSED(width), int UNUSED(height), struct fb_platform_specific *UNUSED(fb_p))
{
        return 0;
}

HIDDEN int
_fb_null_close_existing(fb *UNUSED(ifp))
{
        return 0;
}

HIDDEN int
_fb_null_configure_window(fb *UNUSED(ifp), int UNUSED(width), int UNUSED(height))
{
        return 0;
}

HIDDEN int
_fb_null_refresh(fb *UNUSED(ifp), int UNUSED(x), int UNUSED(y), int UNUSED(w), int UNUSED(h))
{
        return 0;
}

HIDDEN int
_fb_null_close(fb *ifp)
{
    FB_CK_FB(ifp);

    return 0;
}


HIDDEN int
_fb_null_clear(fb *ifp, unsigned char *UNUSED(pp))
{
    FB_CK_FB(ifp);

    return 0;
}


HIDDEN ssize_t
_fb_null_read(fb *ifp, int UNUSED(x), int UNUSED(y), unsigned char *UNUSED(pixelp), size_t count)
{
    FB_CK_FB(ifp);

    return count;
}


HIDDEN ssize_t
_fb_null_write(fb *ifp, int UNUSED(x), int UNUSED(y), const unsigned char *UNUSED(pixelp), size_t count)
{
    FB_CK_FB(ifp);

    return count;
}


HIDDEN int
_fb_null_rmap(fb *ifp, ColorMap *UNUSED(cmp))
{
    FB_CK_FB(ifp);

    return 0;
}


HIDDEN int
_fb_null_wmap(fb *ifp, const ColorMap *UNUSED(cmp))
{
    FB_CK_FB(ifp);

    return 0;
}


HIDDEN int
_fb_null_view(fb *ifp, int UNUSED(xcenter), int UNUSED(ycenter), int UNUSED(xzoom), int UNUSED(yzoom))
{
    FB_CK_FB(ifp);

    /*fb_sim_view(ifp, xcenter, ycenter, xzoom, yzoom);*/
    return 0;
}


HIDDEN int
_fb_null_getview(fb *ifp, int *UNUSED(xcenter), int *UNUSED(ycenter), int *UNUSED(xzoom), int *UNUSED(yzoom))
{
    FB_CK_FB(ifp);

    /*fb_sim_getview(ifp, xcenter, ycenter, xzoom, yzoom);*/
    return 0;
}


HIDDEN int
_fb_null_setcursor(fb *ifp, const unsigned char *UNUSED(bits), int UNUSED(xbits), int UNUSED(ybits), int UNUSED(xorig), int UNUSED(yorig))
{
    FB_CK_FB(ifp);

    return 0;
}


HIDDEN int
_fb_null_cursor(fb *ifp, int UNUSED(mode), int UNUSED(x), int UNUSED(y))
{
    FB_CK_FB(ifp);

    /*fb_sim_cursor(ifp, mode, x, y);*/
    return 0;
}


HIDDEN int
_fb_null_getcursor(fb *ifp, int *UNUSED(mode), int *UNUSED(x), int *UNUSED(y))
{
    FB_CK_FB(ifp);

    /*fb_sim_getcursor(ifp, mode, x, y);*/
    return 0;
}


HIDDEN int
_fb_null_readrect(fb *ifp, int UNUSED(xmin), int UNUSED(ymin), int width, int height, unsigned char *UNUSED(pp))
{
    FB_CK_FB(ifp);

    return width*height;
}


HIDDEN int
_fb_null_writerect(fb *ifp, int UNUSED(xmin), int UNUSED(ymin), int width, int height, const unsigned char *UNUSED(pp))
{
    FB_CK_FB(ifp);

    return width*height;
}


HIDDEN int
_fb_null_poll(fb *ifp)
{
    FB_CK_FB(ifp);

    return 0;
}


HIDDEN int
_fb_null_flush(fb *ifp)
{
    FB_CK_FB(ifp);

    return 0;
}


HIDDEN int
_fb_null_free(fb *ifp)
{
    FB_CK_FB(ifp);

    return 0;
}


HIDDEN int
_fb_null_help(fb *ifp)
{
    FB_CK_FB(ifp);

    fb_log("Description: %s\n", fb_null_interface.if_type);
    fb_log("Device: %s\n", ifp->if_name);
    fb_log("Max width/height: %d %d\n",
	   fb_null_interface.if_max_width,
	   fb_null_interface.if_max_height);
    fb_log("Default width/height: %d %d\n",
	   fb_null_interface.if_width,
	   fb_null_interface.if_height);
    fb_log("Useful for Benchmarking/Debugging\n");
    return 0;
}


/* This is the ONLY thing that we normally "export" */
fb fb_null_interface =  {
    0,
    FB_NULL_MAGIC,
    _fb_null_open,		/* device_open */
    _fb_null_open_existing,	/* existing device_open */
    _fb_null_close_existing,/* existing device_close */
    _fb_null_get_fbps,
    _fb_null_put_fbps,
    _fb_null_close,		/* device_close */
    _fb_null_clear,		/* device_clear */
    _fb_null_read,		/* buffer_read */
    _fb_null_write,		/* buffer_write */
    _fb_null_rmap,		/* colormap_read */
    _fb_null_wmap,		/* colormap_write */
    _fb_null_view,		/* set view */
    _fb_null_getview,	/* get view */
    _fb_null_setcursor,	/* define cursor */
    _fb_null_cursor,	/* set cursor */
    _fb_null_getcursor,	/* get cursor */
    _fb_null_readrect,	/* rectangle read */
    _fb_null_writerect,	/* rectangle write */
    _fb_null_readrect,	/* bw rectangle read */
    _fb_null_writerect,	/* bw rectangle write */
    _fb_null_configure_window,
    _fb_null_refresh,
    _fb_null_poll,		/* handle events */
    _fb_null_flush,		/* flush output */
    _fb_null_free,		/* free resources */
    _fb_null_help,		/* help message */
    "Null Device",	/* device description */
    32*1024,		/* max width */
    32*1024,		/* max height */
    "/dev/null",	/* short device name */
    512,		/* default/current width */
    512,		/* default/current height */
    -1,			/* select fd */
    -1,			/* file descriptor */
    1, 1,		/* zoom */
    256, 256,		/* window center */
    0, 0, 0,		/* cursor */
    PIXEL_NULL,		/* page_base */
    PIXEL_NULL,		/* page_curp */
    PIXEL_NULL,		/* page_endp */
    -1,			/* page_no */
    0,			/* page_dirty */
    0L,			/* page_curpos */
    0L,			/* page_pixels */
    0,			/* debug */
    0,			/* refresh rate */
    {0}, /* u1 */
    {0}, /* u2 */
    {0}, /* u3 */
    {0}, /* u4 */
    {0}, /* u5 */
    {0}  /* u6 */
};


/*
 * Local Variables:
 * mode: C
 * tab-width: 8
 * indent-tabs-mode: t
 * c-file-style: "stroustrup"
 * End:
 * ex: shiftwidth=4 tabstop=8
 */
