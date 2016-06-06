// ---------------------------------
// Copyright (c) 2016 Jens Kallup
// Alle Rechte Vorbehalten!
// ---------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#include "kitest.h"
#include "../xchat-plugin.h"

#include <iostream>
using namespace std;

static xchat_plugin *ph;  // plugin handle

static const char* get_user(void)
{
    return xchat_get_info(ph,"nick");
}

static int get_help(char *word[], char **word_eol, void *userdata)
{
    std::string msg = "konnte ich helfen?'";

    if (strlen(word[2]) < 1)
    xchat_printf(ph,">\tAnwendung: /pc <Frage>");

    std::string str = "SAY ";

    if (!(strcmp(word[2],"hallo")))
    {
        msg  = "Guten Tag: ";
        msg += get_user();
        msg += " - schön Dich wieder zu sehen!";

        if (!(strcmp(word[3],"ich"))) {
            msg  = "führst Du immer noch Selbstgespräche :-) ?";
        }
        else if (!(strcmp(word[3],"pc")))
        {
            msg += "\nDanke! Wie geht es Dir?";
        }
        else if (!(strcmp(word[3],"du"))) {
            msg += "\nwen meinst Du?";
        }

        str += msg;
        xchat_command(ph,str.c_str());
    }
    else {
        msg  = "Guten Tag: ";
        msg += get_user();
        msg += "\nWomit kann ich Ihnen helfen? Ich habe leider Deine Frage nicht verstanden!";
        str += msg;
        xchat_command(ph,str.c_str());
    }
    return XCHAT_EAT_ALL;
}

extern "C" int xchat_plugin_init(
    xchat_plugin *plugin_handle,
    char **plugin_name,
    char **plugin_desc,
    char **plugin_version,
    char  *arg)
{
    ph = plugin_handle;
    *plugin_name = "dBase4Linux";
    *plugin_desc = "kleiner Versuch einer automatisierten Wissensdatenbank.";
    *plugin_version = "0.1";

    xchat_hook_command(
        ph,
        "hlp",
    XCHAT_PRI_NORM,
    get_help,"/pc" ,
    0);

    //xchat_hook_timer(ph, 5000, timeout_cb, 0);

    return 1;
}
