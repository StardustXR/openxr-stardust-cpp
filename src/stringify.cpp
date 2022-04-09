#include "stringify.hpp"
#include <cstring>
#include <unordered_map>

#define NAME(enum) {enum, #enum},

namespace StardustXR {
namespace OpenXR {

static std::unordered_map<XrResult, const char *> resultNames = {	NAME(XR_SUCCESS)
	NAME(XR_TIMEOUT_EXPIRED)
	NAME(XR_SESSION_LOSS_PENDING)
	NAME(XR_EVENT_UNAVAILABLE)
	NAME(XR_SPACE_BOUNDS_UNAVAILABLE)
	NAME(XR_SESSION_NOT_FOCUSED)
	NAME(XR_FRAME_DISCARDED)
	NAME(XR_ERROR_VALIDATION_FAILURE)
	NAME(XR_ERROR_RUNTIME_FAILURE)
	NAME(XR_ERROR_OUT_OF_MEMORY)
	NAME(XR_ERROR_API_VERSION_UNSUPPORTED)
	NAME(XR_ERROR_INITIALIZATION_FAILED)
	NAME(XR_ERROR_FUNCTION_UNSUPPORTED)
	NAME(XR_ERROR_FEATURE_UNSUPPORTED)
	NAME(XR_ERROR_EXTENSION_NOT_PRESENT)
	NAME(XR_ERROR_LIMIT_REACHED)
	NAME(XR_ERROR_SIZE_INSUFFICIENT)
	NAME(XR_ERROR_HANDLE_INVALID)
	NAME(XR_ERROR_INSTANCE_LOST)
	NAME(XR_ERROR_SESSION_RUNNING)
	NAME(XR_ERROR_SESSION_NOT_RUNNING)
	NAME(XR_ERROR_SESSION_LOST)
	NAME(XR_ERROR_SYSTEM_INVALID)
	NAME(XR_ERROR_PATH_INVALID)
	NAME(XR_ERROR_PATH_COUNT_EXCEEDED)
	NAME(XR_ERROR_PATH_FORMAT_INVALID)
	NAME(XR_ERROR_PATH_UNSUPPORTED)
	NAME(XR_ERROR_LAYER_INVALID)
	NAME(XR_ERROR_LAYER_LIMIT_EXCEEDED)
	NAME(XR_ERROR_SWAPCHAIN_RECT_INVALID)
	NAME(XR_ERROR_SWAPCHAIN_FORMAT_UNSUPPORTED)
	NAME(XR_ERROR_ACTION_TYPE_MISMATCH)
	NAME(XR_ERROR_SESSION_NOT_READY)
	NAME(XR_ERROR_SESSION_NOT_STOPPING)
	NAME(XR_ERROR_TIME_INVALID)
	NAME(XR_ERROR_REFERENCE_SPACE_UNSUPPORTED)
	NAME(XR_ERROR_FILE_ACCESS_ERROR)
	NAME(XR_ERROR_FILE_CONTENTS_INVALID)
	NAME(XR_ERROR_FORM_FACTOR_UNSUPPORTED)
	NAME(XR_ERROR_FORM_FACTOR_UNAVAILABLE)
	NAME(XR_ERROR_API_LAYER_NOT_PRESENT)
	NAME(XR_ERROR_CALL_ORDER_INVALID)
	NAME(XR_ERROR_GRAPHICS_DEVICE_INVALID)
	NAME(XR_ERROR_POSE_INVALID)
	NAME(XR_ERROR_INDEX_OUT_OF_RANGE)
	NAME(XR_ERROR_VIEW_CONFIGURATION_TYPE_UNSUPPORTED)
	NAME(XR_ERROR_ENVIRONMENT_BLEND_MODE_UNSUPPORTED)
	NAME(XR_ERROR_NAME_DUPLICATED)
	NAME(XR_ERROR_NAME_INVALID)
	NAME(XR_ERROR_ACTIONSET_NOT_ATTACHED)
	NAME(XR_ERROR_ACTIONSETS_ALREADY_ATTACHED)
	NAME(XR_ERROR_LOCALIZED_NAME_DUPLICATED)
	NAME(XR_ERROR_LOCALIZED_NAME_INVALID)
	NAME(XR_ERROR_GRAPHICS_REQUIREMENTS_CALL_MISSING)
	NAME(XR_ERROR_RUNTIME_UNAVAILABLE)
	NAME(XR_ERROR_ANDROID_THREAD_SETTINGS_ID_INVALID_KHR)
	NAME(XR_ERROR_ANDROID_THREAD_SETTINGS_FAILURE_KHR)
	NAME(XR_ERROR_CREATE_SPATIAL_ANCHOR_FAILED_MSFT)
	NAME(XR_ERROR_SECONDARY_VIEW_CONFIGURATION_TYPE_NOT_ENABLED_MSFT)
	NAME(XR_ERROR_CONTROLLER_MODEL_KEY_INVALID_MSFT)
	NAME(XR_ERROR_REPROJECTION_MODE_UNSUPPORTED_MSFT)
	NAME(XR_ERROR_COMPUTE_NEW_SCENE_NOT_COMPLETED_MSFT)
	NAME(XR_ERROR_SCENE_COMPONENT_ID_INVALID_MSFT)
	NAME(XR_ERROR_SCENE_COMPONENT_TYPE_MISMATCH_MSFT)
	NAME(XR_ERROR_SCENE_MESH_BUFFER_ID_INVALID_MSFT)
	NAME(XR_ERROR_SCENE_COMPUTE_FEATURE_INCOMPATIBLE_MSFT)
	NAME(XR_ERROR_SCENE_COMPUTE_CONSISTENCY_MISMATCH_MSFT)
	NAME(XR_ERROR_DISPLAY_REFRESH_RATE_UNSUPPORTED_FB)
	NAME(XR_ERROR_COLOR_SPACE_UNSUPPORTED_FB)
	// NAME(XR_ERROR_UNEXPECTED_STATE_PASSTHROUGH_FB)
	// NAME(XR_ERROR_FEATURE_ALREADY_CREATED_PASSTHROUGH_FB)
	// NAME(XR_ERROR_FEATURE_REQUIRED_PASSTHROUGH_FB)
	// NAME(XR_ERROR_NOT_PERMITTED_PASSTHROUGH_FB)
	// NAME(XR_ERROR_INSUFFICIENT_RESOURCES_PASSTHROUGH_FB)
	// NAME(XR_ERROR_UNKNOWN_PASSTHROUGH_FB)
	// NAME(XR_ERROR_RENDER_MODEL_KEY_INVALID_FB)
	// NAME(XR_RENDER_MODEL_UNAVAILABLE_FB)
	// NAME(XR_ERROR_MARKER_NOT_TRACKED_VARJO)
	// NAME(XR_ERROR_MARKER_ID_INVALID_VARJO)
	NAME(XR_ERROR_SPATIAL_ANCHOR_NAME_NOT_FOUND_MSFT)
	NAME(XR_ERROR_SPATIAL_ANCHOR_NAME_INVALID_MSFT)
};

XrResult xrResultToString(XrInstance instance, XrResult value, char *buffer) {
	strncpy(buffer, resultNames[value], XR_MAX_RESULT_STRING_SIZE);
	return XR_SUCCESS;
}


static std::unordered_map<XrStructureType, const char *> structTypeNames {
	NAME(XR_TYPE_UNKNOWN)
	NAME(XR_TYPE_API_LAYER_PROPERTIES)
	NAME(XR_TYPE_EXTENSION_PROPERTIES)
	NAME(XR_TYPE_INSTANCE_CREATE_INFO)
	NAME(XR_TYPE_SYSTEM_GET_INFO)
	NAME(XR_TYPE_SYSTEM_PROPERTIES)
	NAME(XR_TYPE_VIEW_LOCATE_INFO)
	NAME(XR_TYPE_VIEW)
	NAME(XR_TYPE_SESSION_CREATE_INFO)
	NAME(XR_TYPE_SWAPCHAIN_CREATE_INFO)
	NAME(XR_TYPE_SESSION_BEGIN_INFO)
	NAME(XR_TYPE_VIEW_STATE)
	NAME(XR_TYPE_FRAME_END_INFO)
	NAME(XR_TYPE_HAPTIC_VIBRATION)
	NAME(XR_TYPE_EVENT_DATA_BUFFER)
	NAME(XR_TYPE_EVENT_DATA_INSTANCE_LOSS_PENDING)
	NAME(XR_TYPE_EVENT_DATA_SESSION_STATE_CHANGED)
	NAME(XR_TYPE_ACTION_STATE_BOOLEAN)
	NAME(XR_TYPE_ACTION_STATE_FLOAT)
	NAME(XR_TYPE_ACTION_STATE_VECTOR2F)
	NAME(XR_TYPE_ACTION_STATE_POSE)
	NAME(XR_TYPE_ACTION_SET_CREATE_INFO)
	NAME(XR_TYPE_ACTION_CREATE_INFO)
	NAME(XR_TYPE_INSTANCE_PROPERTIES)
	NAME(XR_TYPE_FRAME_WAIT_INFO)
	NAME(XR_TYPE_COMPOSITION_LAYER_PROJECTION)
	NAME(XR_TYPE_COMPOSITION_LAYER_QUAD)
	NAME(XR_TYPE_REFERENCE_SPACE_CREATE_INFO)
	NAME(XR_TYPE_ACTION_SPACE_CREATE_INFO)
	NAME(XR_TYPE_EVENT_DATA_REFERENCE_SPACE_CHANGE_PENDING)
	NAME(XR_TYPE_VIEW_CONFIGURATION_VIEW)
	NAME(XR_TYPE_SPACE_LOCATION)
	NAME(XR_TYPE_SPACE_VELOCITY)
	NAME(XR_TYPE_FRAME_STATE)
	NAME(XR_TYPE_VIEW_CONFIGURATION_PROPERTIES)
	NAME(XR_TYPE_FRAME_BEGIN_INFO)
	NAME(XR_TYPE_COMPOSITION_LAYER_PROJECTION_VIEW)
	NAME(XR_TYPE_EVENT_DATA_EVENTS_LOST)
	NAME(XR_TYPE_INTERACTION_PROFILE_SUGGESTED_BINDING)
	NAME(XR_TYPE_EVENT_DATA_INTERACTION_PROFILE_CHANGED)
	NAME(XR_TYPE_INTERACTION_PROFILE_STATE)
	NAME(XR_TYPE_SWAPCHAIN_IMAGE_ACQUIRE_INFO)
	NAME(XR_TYPE_SWAPCHAIN_IMAGE_WAIT_INFO)
	NAME(XR_TYPE_SWAPCHAIN_IMAGE_RELEASE_INFO)
	NAME(XR_TYPE_ACTION_STATE_GET_INFO)
	NAME(XR_TYPE_HAPTIC_ACTION_INFO)
	NAME(XR_TYPE_SESSION_ACTION_SETS_ATTACH_INFO)
	NAME(XR_TYPE_ACTIONS_SYNC_INFO)
	NAME(XR_TYPE_BOUND_SOURCES_FOR_ACTION_ENUMERATE_INFO)
	NAME(XR_TYPE_INPUT_SOURCE_LOCALIZED_NAME_GET_INFO)
	NAME(XR_TYPE_COMPOSITION_LAYER_CUBE_KHR)
	NAME(XR_TYPE_INSTANCE_CREATE_INFO_ANDROID_KHR)
	NAME(XR_TYPE_COMPOSITION_LAYER_DEPTH_INFO_KHR)
	NAME(XR_TYPE_VULKAN_SWAPCHAIN_FORMAT_LIST_CREATE_INFO_KHR)
	NAME(XR_TYPE_EVENT_DATA_PERF_SETTINGS_EXT)
	NAME(XR_TYPE_COMPOSITION_LAYER_CYLINDER_KHR)
	NAME(XR_TYPE_COMPOSITION_LAYER_EQUIRECT_KHR)
	NAME(XR_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT)
	NAME(XR_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT)
	NAME(XR_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT)
	NAME(XR_TYPE_DEBUG_UTILS_LABEL_EXT)
	NAME(XR_TYPE_GRAPHICS_BINDING_OPENGL_WIN32_KHR)
	NAME(XR_TYPE_GRAPHICS_BINDING_OPENGL_XLIB_KHR)
	NAME(XR_TYPE_GRAPHICS_BINDING_OPENGL_XCB_KHR)
	NAME(XR_TYPE_GRAPHICS_BINDING_OPENGL_WAYLAND_KHR)
	NAME(XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_KHR)
	NAME(XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_KHR)
	NAME(XR_TYPE_GRAPHICS_BINDING_OPENGL_ES_ANDROID_KHR)
	NAME(XR_TYPE_SWAPCHAIN_IMAGE_OPENGL_ES_KHR)
	NAME(XR_TYPE_GRAPHICS_REQUIREMENTS_OPENGL_ES_KHR)
	NAME(XR_TYPE_GRAPHICS_BINDING_VULKAN_KHR)
	NAME(XR_TYPE_SWAPCHAIN_IMAGE_VULKAN_KHR)
	NAME(XR_TYPE_GRAPHICS_REQUIREMENTS_VULKAN_KHR)
	NAME(XR_TYPE_GRAPHICS_BINDING_D3D11_KHR)
	NAME(XR_TYPE_SWAPCHAIN_IMAGE_D3D11_KHR)
	NAME(XR_TYPE_GRAPHICS_REQUIREMENTS_D3D11_KHR)
	NAME(XR_TYPE_GRAPHICS_BINDING_D3D12_KHR)
	NAME(XR_TYPE_SWAPCHAIN_IMAGE_D3D12_KHR)
	NAME(XR_TYPE_GRAPHICS_REQUIREMENTS_D3D12_KHR)
	NAME(XR_TYPE_SYSTEM_EYE_GAZE_INTERACTION_PROPERTIES_EXT)
	NAME(XR_TYPE_EYE_GAZE_SAMPLE_TIME_EXT)
	NAME(XR_TYPE_VISIBILITY_MASK_KHR)
	NAME(XR_TYPE_EVENT_DATA_VISIBILITY_MASK_CHANGED_KHR)
	NAME(XR_TYPE_SESSION_CREATE_INFO_OVERLAY_EXTX)
	NAME(XR_TYPE_EVENT_DATA_MAIN_SESSION_VISIBILITY_CHANGED_EXTX)
	NAME(XR_TYPE_COMPOSITION_LAYER_COLOR_SCALE_BIAS_KHR)
	NAME(XR_TYPE_SPATIAL_ANCHOR_CREATE_INFO_MSFT)
	NAME(XR_TYPE_SPATIAL_ANCHOR_SPACE_CREATE_INFO_MSFT)
	NAME(XR_TYPE_COMPOSITION_LAYER_IMAGE_LAYOUT_FB)
	NAME(XR_TYPE_COMPOSITION_LAYER_ALPHA_BLEND_FB)
	NAME(XR_TYPE_VIEW_CONFIGURATION_DEPTH_RANGE_EXT)
	NAME(XR_TYPE_GRAPHICS_BINDING_EGL_MNDX)
	NAME(XR_TYPE_SPATIAL_GRAPH_NODE_SPACE_CREATE_INFO_MSFT)
	NAME(XR_TYPE_SYSTEM_HAND_TRACKING_PROPERTIES_EXT)
	NAME(XR_TYPE_HAND_TRACKER_CREATE_INFO_EXT)
	NAME(XR_TYPE_HAND_JOINTS_LOCATE_INFO_EXT)
	NAME(XR_TYPE_HAND_JOINT_LOCATIONS_EXT)
	NAME(XR_TYPE_HAND_JOINT_VELOCITIES_EXT)
	NAME(XR_TYPE_SYSTEM_HAND_TRACKING_MESH_PROPERTIES_MSFT)
	NAME(XR_TYPE_HAND_MESH_SPACE_CREATE_INFO_MSFT)
	NAME(XR_TYPE_HAND_MESH_UPDATE_INFO_MSFT)
	NAME(XR_TYPE_HAND_MESH_MSFT)
	NAME(XR_TYPE_HAND_POSE_TYPE_INFO_MSFT)
	NAME(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SESSION_BEGIN_INFO_MSFT)
	NAME(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_STATE_MSFT)
	NAME(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_STATE_MSFT)
	NAME(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_FRAME_END_INFO_MSFT)
	NAME(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_LAYER_INFO_MSFT)
	NAME(XR_TYPE_SECONDARY_VIEW_CONFIGURATION_SWAPCHAIN_CREATE_INFO_MSFT)
	NAME(XR_TYPE_CONTROLLER_MODEL_KEY_STATE_MSFT)
	NAME(XR_TYPE_CONTROLLER_MODEL_NODE_PROPERTIES_MSFT)
	NAME(XR_TYPE_CONTROLLER_MODEL_PROPERTIES_MSFT)
	NAME(XR_TYPE_CONTROLLER_MODEL_NODE_STATE_MSFT)
	NAME(XR_TYPE_CONTROLLER_MODEL_STATE_MSFT)
	NAME(XR_TYPE_VIEW_CONFIGURATION_VIEW_FOV_EPIC)
	NAME(XR_TYPE_HOLOGRAPHIC_WINDOW_ATTACHMENT_MSFT)
	NAME(XR_TYPE_COMPOSITION_LAYER_REPROJECTION_INFO_MSFT)
	NAME(XR_TYPE_COMPOSITION_LAYER_REPROJECTION_PLANE_OVERRIDE_MSFT)
	NAME(XR_TYPE_ANDROID_SURFACE_SWAPCHAIN_CREATE_INFO_FB)
	NAME(XR_TYPE_COMPOSITION_LAYER_SECURE_CONTENT_FB)
	NAME(XR_TYPE_INTERACTION_PROFILE_ANALOG_THRESHOLD_VALVE)
	NAME(XR_TYPE_HAND_JOINTS_MOTION_RANGE_INFO_EXT)
	NAME(XR_TYPE_LOADER_INIT_INFO_ANDROID_KHR)
	NAME(XR_TYPE_VULKAN_INSTANCE_CREATE_INFO_KHR)
	NAME(XR_TYPE_VULKAN_DEVICE_CREATE_INFO_KHR)
	NAME(XR_TYPE_VULKAN_GRAPHICS_DEVICE_GET_INFO_KHR)
	NAME(XR_TYPE_COMPOSITION_LAYER_EQUIRECT2_KHR)
	NAME(XR_TYPE_SCENE_OBSERVER_CREATE_INFO_MSFT)
	NAME(XR_TYPE_SCENE_CREATE_INFO_MSFT)
	NAME(XR_TYPE_NEW_SCENE_COMPUTE_INFO_MSFT)
	NAME(XR_TYPE_VISUAL_MESH_COMPUTE_LOD_INFO_MSFT)
	NAME(XR_TYPE_SCENE_COMPONENTS_MSFT)
	NAME(XR_TYPE_SCENE_COMPONENTS_GET_INFO_MSFT)
	NAME(XR_TYPE_SCENE_COMPONENT_LOCATIONS_MSFT)
	NAME(XR_TYPE_SCENE_COMPONENTS_LOCATE_INFO_MSFT)
	NAME(XR_TYPE_SCENE_OBJECTS_MSFT)
	NAME(XR_TYPE_SCENE_COMPONENT_PARENT_FILTER_INFO_MSFT)
	NAME(XR_TYPE_SCENE_OBJECT_TYPES_FILTER_INFO_MSFT)
	NAME(XR_TYPE_SCENE_PLANES_MSFT)
	NAME(XR_TYPE_SCENE_PLANE_ALIGNMENT_FILTER_INFO_MSFT)
	NAME(XR_TYPE_SCENE_MESHES_MSFT)
	NAME(XR_TYPE_SCENE_MESH_BUFFERS_GET_INFO_MSFT)
	NAME(XR_TYPE_SCENE_MESH_BUFFERS_MSFT)
	NAME(XR_TYPE_SCENE_MESH_VERTEX_BUFFER_MSFT)
	NAME(XR_TYPE_SCENE_MESH_INDICES_UINT32_MSFT)
	NAME(XR_TYPE_SCENE_MESH_INDICES_UINT16_MSFT)
	NAME(XR_TYPE_SERIALIZED_SCENE_FRAGMENT_DATA_GET_INFO_MSFT)
	NAME(XR_TYPE_SCENE_DESERIALIZE_INFO_MSFT)
	NAME(XR_TYPE_EVENT_DATA_DISPLAY_REFRESH_RATE_CHANGED_FB)
	// NAME(XR_TYPE_VIVE_TRACKER_PATHS_HTCX)
	// NAME(XR_TYPE_EVENT_DATA_VIVE_TRACKER_CONNECTED_HTCX)
	// NAME(XR_TYPE_SYSTEM_FACIAL_TRACKING_PROPERTIES_HTC)
	// NAME(XR_TYPE_FACIAL_TRACKER_CREATE_INFO_HTC)
	// NAME(XR_TYPE_FACIAL_EXPRESSIONS_HTC)
	NAME(XR_TYPE_SYSTEM_COLOR_SPACE_PROPERTIES_FB)
	NAME(XR_TYPE_HAND_TRACKING_MESH_FB)
	NAME(XR_TYPE_HAND_TRACKING_SCALE_FB)
	NAME(XR_TYPE_HAND_TRACKING_AIM_STATE_FB)
	NAME(XR_TYPE_HAND_TRACKING_CAPSULES_STATE_FB)
	NAME(XR_TYPE_FOVEATION_PROFILE_CREATE_INFO_FB)
	NAME(XR_TYPE_SWAPCHAIN_CREATE_INFO_FOVEATION_FB)
	NAME(XR_TYPE_SWAPCHAIN_STATE_FOVEATION_FB)
	NAME(XR_TYPE_FOVEATION_LEVEL_PROFILE_CREATE_INFO_FB)
	// NAME(XR_TYPE_KEYBOARD_SPACE_CREATE_INFO_FB)
	// NAME(XR_TYPE_KEYBOARD_TRACKING_QUERY_FB)
	// NAME(XR_TYPE_SYSTEM_KEYBOARD_TRACKING_PROPERTIES_FB)
	// NAME(XR_TYPE_TRIANGLE_MESH_CREATE_INFO_FB)
	// NAME(XR_TYPE_SYSTEM_PASSTHROUGH_PROPERTIES_FB)
	// NAME(XR_TYPE_PASSTHROUGH_CREATE_INFO_FB)
	// NAME(XR_TYPE_PASSTHROUGH_LAYER_CREATE_INFO_FB)
	// NAME(XR_TYPE_COMPOSITION_LAYER_PASSTHROUGH_FB)
	// NAME(XR_TYPE_GEOMETRY_INSTANCE_CREATE_INFO_FB)
	// NAME(XR_TYPE_GEOMETRY_INSTANCE_TRANSFORM_FB)
	// NAME(XR_TYPE_PASSTHROUGH_STYLE_FB)
	// NAME(XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_RGBA_FB)
	// NAME(XR_TYPE_PASSTHROUGH_COLOR_MAP_MONO_TO_MONO_FB)
	// NAME(XR_TYPE_EVENT_DATA_PASSTHROUGH_STATE_CHANGED_FB)
	// NAME(XR_TYPE_RENDER_MODEL_PATH_INFO_FB)
	// NAME(XR_TYPE_RENDER_MODEL_PROPERTIES_FB)
	// NAME(XR_TYPE_RENDER_MODEL_BUFFER_FB)
	// NAME(XR_TYPE_RENDER_MODEL_LOAD_INFO_FB)
	// NAME(XR_TYPE_SYSTEM_RENDER_MODEL_PROPERTIES_FB)
	NAME(XR_TYPE_BINDING_MODIFICATIONS_KHR)
	NAME(XR_TYPE_VIEW_LOCATE_FOVEATED_RENDERING_VARJO)
	NAME(XR_TYPE_FOVEATED_VIEW_CONFIGURATION_VIEW_VARJO)
	NAME(XR_TYPE_SYSTEM_FOVEATED_RENDERING_PROPERTIES_VARJO)
	NAME(XR_TYPE_COMPOSITION_LAYER_DEPTH_TEST_VARJO)
	// NAME(XR_TYPE_SYSTEM_MARKER_TRACKING_PROPERTIES_VARJO)
	// NAME(XR_TYPE_EVENT_DATA_MARKER_TRACKING_UPDATE_VARJO)
	// NAME(XR_TYPE_MARKER_SPACE_CREATE_INFO_VARJO)
	NAME(XR_TYPE_SPATIAL_ANCHOR_PERSISTENCE_INFO_MSFT)
	NAME(XR_TYPE_SPATIAL_ANCHOR_FROM_PERSISTED_ANCHOR_CREATE_INFO_MSFT)
	NAME(XR_TYPE_SWAPCHAIN_IMAGE_FOVEATION_VULKAN_FB)
	NAME(XR_TYPE_SWAPCHAIN_STATE_ANDROID_SURFACE_DIMENSIONS_FB)
	NAME(XR_TYPE_SWAPCHAIN_STATE_SAMPLER_OPENGL_ES_FB)
	NAME(XR_TYPE_SWAPCHAIN_STATE_SAMPLER_VULKAN_FB)
	NAME(XR_TYPE_COMPOSITION_LAYER_SPACE_WARP_INFO_FB)
	NAME(XR_TYPE_SYSTEM_SPACE_WARP_PROPERTIES_FB)
	// NAME(XR_TYPE_DIGITAL_LENS_CONTROL_ALMALENCE)
	// NAME(XR_TYPE_PASSTHROUGH_KEYBOARD_HANDS_INTENSITY_FB)
};


XrResult xrStructureTypeToString(XrInstance instance, XrStructureType value, char *buffer) {
	strncpy(buffer, structTypeNames[value], XR_MAX_RESULT_STRING_SIZE);
	return XR_SUCCESS;
}

static std::unordered_map<XrReferenceSpaceType, std::string> referenceSpaceTypeNames {
	NAME(XR_REFERENCE_SPACE_TYPE_VIEW)
    NAME(XR_REFERENCE_SPACE_TYPE_LOCAL)
    NAME(XR_REFERENCE_SPACE_TYPE_STAGE)
    NAME(XR_REFERENCE_SPACE_TYPE_UNBOUNDED_MSFT)
    NAME(XR_REFERENCE_SPACE_TYPE_COMBINED_EYE_VARJO)
};

std::string xrReferenceTypeToString(XrReferenceSpaceType value) {
	return referenceSpaceTypeNames[value];
}

}
}