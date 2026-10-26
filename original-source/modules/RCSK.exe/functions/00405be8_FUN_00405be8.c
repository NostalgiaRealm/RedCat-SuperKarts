/*
 * FUN_00405be8 at 00405be8
 * int __cdecl FUN_00405be8(uint param_1, int param_2)
 * Address ranges: 00405be8-00405c5d
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int __cdecl FUN_00405be8(uint param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  
  if (param_1 < DAT_0040a120) {
    bVar1 = *(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8);
    if ((bVar1 & 1) != 0) {
      if (param_2 == 0x8000) {
        bVar2 = bVar1 & 0x7f;
      }
      else {
        if (param_2 != 0x4000) {
          DAT_00408c04 = 0x16;
          return -1;
        }
        bVar2 = bVar1 | 0x80;
      }
      *(byte *)((&DAT_0040a020)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 8) = bVar2;
      return (-(uint)((bVar1 & 0x80) != 0) & 0xffffc000) + 0x8000;
    }
  }
  DAT_00408c04 = 9;
  return -1;
}

