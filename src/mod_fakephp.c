/*
 * The following license applies to "mod_fakephp" version 0.1. It is a
 * third-party module by Dave Ingram <apache@dmi.me.uk> for the Apache
 * HTTP Server (http://httpd.apache.org/).
 *
 * This license is basically the same as Apache, with the additional
 * provision that any modification must be properly documented.
 *
 * =====================================================================
 * Copyright (c) 2008 David Ingram. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *
 * 3. The end-user documentation included with the redistribution, if
 *    any, must include the following acknowledgment:
 *    "This product includes software developed by David Ingram
 *    <apache@dmi.me.uk> for use in the mod_fakephp project
 *    (http://www.dmi.me.uk/code/apache/mod_fakephp/)." Alternately,
 *    this acknowledgment may appear in the software itself, if and
 *    wherever such third-party acknowledgments normally appear.
 *
 * 4. The name "mod_fakephp" must not be used to endorse or promote
 *    products derived from this software without prior written
 *    permission.  For written permission, please contact Dave Ingram
 *    <apache@dmi.me.uk>.
 *
 * 5. Products derived from this software may not be called
 *    "mod_fakephp" nor may "mod_fakephp" appear in their names without
 *    prior written permission of Dave Ingram.
 *
 * 6. Any modification must be properly documented and acknowledged by
 *    its author.
 *
 * THIS SOFTWARE IS PROVIDED BY DAVID INGRAM ``AS IS'' AND ANY
 * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE APACHE GROUP OR ITS
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 * ====================================================================
 */

#include "httpd.h"
#include "http_config.h"
#include "http_protocol.h"
#include "ap_config.h"

static const char *php_dummy_admin_handler(cmd_parms *cmd, void *dummy, const char *name, const char *value)
{
    return NULL;
}

static const char *php_dummy_handler(cmd_parms *cmd, void *dummy, const char *name, const char *value)
{
    return NULL;
}

/*
 * Command table
 */
static const command_rec fakephp_cmds[] =
{
#ifndef NO_ADMIN_CMDS
  AP_INIT_TAKE2("php_admin_value", php_dummy_admin_handler, NULL, ACCESS_CONF|RSRC_CONF, "Dummy (Admin) PHP Value Command"),
  AP_INIT_TAKE2("php_admin_flag", php_dummy_admin_handler, NULL, ACCESS_CONF|RSRC_CONF, "Dummy (Admin) PHP Flag Command"),
#endif /* NO_ADMIN_CMDS */
  AP_INIT_TAKE2("php_flag", php_dummy_handler, NULL, OR_OPTIONS, "Dummy PHP Flag Command"),
  AP_INIT_TAKE2("php_value", php_dummy_handler, NULL, OR_OPTIONS, "Dummy PHP Value Command"),
  { NULL }
};

/* Dispatch list for API hooks */
module AP_MODULE_DECLARE_DATA fakephp_module = {
    STANDARD20_MODULE_STUFF,
    NULL,                  /* create per-dir    config structures */
    NULL,                  /* merge  per-dir    config structures */
    NULL,                  /* create per-server config structures */
    NULL,                  /* merge  per-server config structures */
    fakephp_cmds,          /* table of config file commands       */
    NULL,                  /* register hooks                      */
};

