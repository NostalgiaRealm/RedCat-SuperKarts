/*
 * FUN_0041e730 at 0041e730
 * undefined __stdcall FUN_0041e730(void)
 * Address ranges: 0041e730-0041e758
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e730(void)

{
  FUN_004015a6((byte *)s_init_video_library__version__s_00436d98);
  CoInitialize((LPVOID)0x0);
  AVIFileInit();
  FUN_0041e770();
  FUN_0041e800();
  return;
}

