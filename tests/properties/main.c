#include <stdio.h>
#include <cutils/properties.h>

#define GET_PROPERTY_ANDROID(key, value, default_value) \
    char value[PROPERTY_VALUE_MAX];             \
    property_get(key, value, default_value);

#define GET_PROPERTY(key, value, default_value)                 \
    char * value = getenv(key);   \
    if (value == NULL) {          \
        value = (char *) default_value;                         \
    }


int main(void)
{
	char value[PROPERTY_VALUE_MAX];
	property_get("ste.cam.ext.cfg.path.secondary", value, "null");

	printf("ste.cam.ext.cfg.path.secondary = %s\n", value);


	char * value2 = getenv("ste.cam.ext.cfg.path.secondary");
	if (value2 == NULL)
		value2 = (char *) "null";

	printf("ste.cam.ext.cfg.path.secondary = %s\n", value2);

	return 0;
}
