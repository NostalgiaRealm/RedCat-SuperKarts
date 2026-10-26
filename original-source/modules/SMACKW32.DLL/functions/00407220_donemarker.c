/*
 * donemarker at 00407220
 * undefined __stdcall donemarker(UINT param_1, undefined4 param_2, int param_3)
 * Address ranges: 00407220-00407236
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 * Analysis note: __stdcall donemarker,20
 */

/* __stdcall donemarker,20 */

void donemarker(UINT param_1,undefined4 param_2,int param_3)

{
                    /* 0x7220  34  _donemarker@20 */
  *(byte *)(param_3 + 0x10) = *(byte *)(param_3 + 0x10) | 1;
  timeKillEvent(param_1);
  return;
}

