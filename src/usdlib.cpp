#include "usdlib.h"

#include <pxr/usd/usd/primRange.h>
#include <pxr/usd/usd/stage.h>
#include <pxr/usd/usdGeom/pointBased.h>
#include <pxr/usd/sdf/layer.h>
#include <pxr/pxr.h>
#include <iostream>

#include <map>

PXR_NAMESPACE_USING_DIRECTIVE

namespace usdproxy
{
    void Test2::DoSomething()
    {

    }
}

extern "C"
{
    int dostage()
    {
           // Path to the USD file
            const std::string filePath = "d:\\temp\\simple.usda";

            // Create a USD stage
            pxr::UsdStageRefPtr stage = pxr::UsdStage::Open(filePath);

            if (!stage) {
                std::cerr << "Failed to open USD stage." << std::endl;
                return 1;
            }

            // Get the root layer of the USD stage
            pxr::SdfLayerHandle rootLayer = stage->GetRootLayer();

            // Iterate over the prims in the stage
            for (const pxr::UsdPrim& prim : stage->Traverse()) {
                // Check if the prim is a point-based primitive
                if (prim.IsA<pxr::UsdGeomPointBased>()) {
                    std::cout << "Found a point-based primitive: " << prim.GetPath() << std::endl;

                    // Perform operations specific to USDGeomPointBased

                    // Example: Accessing the points attribute
                    pxr::UsdGeomPointBased pointBased(prim);
                    pxr::UsdAttribute pointsAttr = pointBased.GetPointsAttr();

                    // Example: Getting the number of points
                    pxr::VtArray<pxr::GfVec3f> points;
                    pointsAttr.Get(&points);
                    std::cout << "Number of points: " << points.size() << std::endl;

                    // Example: Accessing the position of the first point
                    if (!points.empty()) {
                        pxr::GfVec3f firstPoint = points[0];
                        std::cout << "Position of the first point: (" << firstPoint[0] << ", "
                                  << firstPoint[1] << ", " << firstPoint[2] << ")" << std::endl;
                    }
                }
            }
            return 0;
        }
}
