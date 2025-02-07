const std = @import("std");
pub export fn zig() callconv(.C) void {
    std.io.getStdOut().writer().print("Hi from Zig!\n", .{}) catch unreachable;

}