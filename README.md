Profiler for Godot
=========================

A CPU time instrumenting profiler for Godot Engine.

![Client GUI embedded in a game](screenshot.png)

This allows to add profiling scopes to any part of the C++ codebase in Godot, so that much better insight about what's happening can be provided to users. Besides, scripts can also make use of it thanks to the recent addition of a `StringName`-based API.

It was primarily used in Voxel Tools C++ codebase as a simple profiling solution, but evolved to become independent. It's still relatively work in progress, but mostly usable.
Old Git history was lost in the migration, but can be found in the `profiler` branch of Voxel Tools.


Features
---------------------------

- Function and scope sampling in C++ by adding a single macro
- API supports either string literal (fastest) or `StringName` for script-friendly usage
- Microsecond accuracy using Godot's time functions
- Multithreaded: each thread can be recorded independently
- Client/server architecture: the server records, the client displays.
- Client GUI made with Godot nodes, can be embedded in game or in editor
- Timeline with pan & zoom showing all the measured calls
- Tree view showing call hierarchy and time taken
- Sample categories (so we can distinguish easily when an item is in C++ or a script)
- Starts recording when a connection from the client is made


How To Install And Use
-------------------------

ZProfiler is a custom C++ module for Godot 3.1+. It must be compiled into the engine to work.

As a module, it holds a particular place because in theory, any place of 


Roadmap
---------

These are some ideas that may or may not be implemented in the future:

* Resolving function names in C++ (the preprocessor doesn't know them so they aren't literals)
* Fix issues related to `ThreadLocal` resource management (potential leaks)
* Script API exposition (although it could record automatically by function in GDScript's runtime)
* Save data to files for later inspection (was originally working this way but got removed temporarily)
* True integration with Godot's official profiler, through a PR to the engine
