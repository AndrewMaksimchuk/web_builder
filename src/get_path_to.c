#include "variables.h"

void get_path_to()
{
    switch (0)
    {
    case 0:
        page_path = concat(project_path, "/src/page");
    case 1:
        component_path = concat(project_path, "/src/component");
    case 2:
        unit_path = concat(project_path, "/src/unit");
    }
}