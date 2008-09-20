mod_fakephp.la: mod_fakephp.slo
	$(SH_LINK) -rpath $(libexecdir) -module -avoid-version  mod_fakephp.lo
DISTCLEAN_TARGETS = modules.mk
shared =  mod_fakephp.la
