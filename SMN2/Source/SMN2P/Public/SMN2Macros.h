#pragma once

#define likely(x) \
	(x) [[likely]]

#define unlikely(x) \
	(x) [[unlikely]]