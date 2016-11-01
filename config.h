/* See LICENSE file for copyright and license details. */

/* appearance */
static const char font[]            = "-*-terminus-medium-r-*-*-22-*-*-*-*-*-*-*";
static const char normbordercolor[] = "#000000";
static const char normbgcolor[]     = "#000000";
static const char normfgcolor[]     = "#49e20e";
static const char selbordercolor[]  = "#000000";
static const char selbgcolor[]      = "#000000";
static const char selfgcolor[]      = "#49e20e";
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
   /* class      instance    title       tags mask     isfloating   monitor */
   { "Pidgin",      NULL,       NULL,       1 << 7,            False,       -1 },
   /* { "chromium",    NULL,       NULL,       1 << 8,            False,       -1 }, */
};

/* layout(s) */
static const float mfact      = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;    /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "-",      tile },    /* first entry is default */
    { "~",      NULL },    /* no layout function means floating behavior */
    { "0",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *dmenucmd[] = { "dmenu_run", "-fn", "-*-terminus-medium-*-*-*-*-180-*-*-*-*-*-*", "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *termcmd[]  = { "xterm", NULL };
static const char *chromium[] = { "chromium", "--auth-server-whitelist=*.caltech.edu", NULL };
static const char *volup[] = { "volup", NULL };
static const char *voldown[] = { "voldown", NULL };
static const char *voltoggle[] = { "voltoggle", NULL };
static const char *brightup[] = { "brightup", NULL };
static const char *brightdown[] = { "brightdown", NULL };
static const char *changekeys[] = { "changekeys", NULL };
static const char *toggleInt[] = { "toggleInt", NULL };
static const char *tptoggle[] = { "tptoggle", NULL };
static const char *transtoggle[] = { "transToggle", NULL };
static const char *compmgrToggle[] = { "compmgrToggle", NULL };
static const char *rebg[] = { "rebg", NULL };
static const char *gdict[] = { "goldendict", NULL };
static const char *paste_x[] = { "paste_x", NULL };
static const char *paste_c[] = { "paste_x", "-c", NULL };
static const char *paste_s[] = { "paste_x", "-shrug", NULL };
static const char *xscreensaver[] = { "xscreensaver-command", "-lock", NULL };

static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_F1,     spawn,          {.v = changekeys } },
    { MODKEY|ShiftMask,             XK_F1,     spawn,          {.v = toggleInt } },
    { MODKEY,                       XK_F2,     spawn,          {.v = brightdown } },
    { MODKEY,                       XK_F3,     spawn,          {.v = brightup } },
    { MODKEY,                       XK_F4,     spawn,          {.v = transtoggle } },
    { MODKEY|ShiftMask,             XK_F4,     spawn,          {.v = compmgrToggle } },
    { MODKEY,                       XK_F5,     spawn,          {.v = rebg } },
    { MODKEY,                       XK_F9,     spawn,          {.v = voldown } },
    { MODKEY,                       XK_F10,    spawn,          {.v = volup} },
    { MODKEY,                       XK_F11,    spawn,          {.v = voltoggle } },
    { MODKEY,                       XK_F12,    spawn,          {.v = tptoggle } },
    { MODKEY,                       XK_q,      spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_period, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_comma,  spawn,          {.v = chromium } },
    { MODKEY,                       XK_u,      spawn,          {.v = gdict } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY,                       XK_h,      setmfact,       {.f = -0.02} },
    { MODKEY,                       XK_l,      setmfact,       {.f = +0.02} },
    { MODKEY|ShiftMask,             XK_h,      zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_space,  setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    { MODKEY,                       XK_c,      focusmon,       {.i = -1 } },
    { MODKEY,                       XK_r,      focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_c,      tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_r,      tagmon,         {.i = +1 } },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_Escape, quit,           {0} },
    { MODKEY|ShiftMask,             XK_l,      spawn,          {.v = xscreensaver } },
    { MODKEY,                       XK_Return, spawn,          {.v = paste_x } },
    { MODKEY|ShiftMask,             XK_Return, spawn,          {.v = paste_c } },
    { MODKEY,                       XK_s,      spawn,          {.v = paste_s } },
};



/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

