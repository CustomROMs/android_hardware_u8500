#include <stdio.h>
#include <cutils/properties.h>
#include <log/log.h>

void test(void)
{
	ALOGE("test: entered");
}

void test2(void)
{
	ALOGE("test2: entered");
}

#if 0
char * zetenv(const char *key)
{
	char value[PROPERTY_VALUE_MAX];

	ALOGE("called zetenv: key=%s\n", key);
	property_get(key, value, "");
	//if (value)
	ALOGE("zetenv: value=%s\n", value);
	//else
	//	ALOGE("zetenv: value=NULL\n");

	return value;
}

int property_zet(const char *key, char *value, const char * default_value)
{
	int res = 0;

	ALOGE("called property_zet: key=%s\n, default_value=%s", key, default_value);
	res = property_get(key, value, default_value);
	ALOGE("property_zet: value=%s, res=%d\n", value, res);

	return res;

}
#endif
