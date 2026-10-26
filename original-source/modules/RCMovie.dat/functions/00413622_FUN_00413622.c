/*
 * FUN_00413622 at 00413622
 * undefined4 __cdecl FUN_00413622(int * param_1, char * param_2)
 * Address ranges: 00413622-00413839
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_00413622(int *param_1,char *param_2)

{
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  FUN_00409b18(param_1,-0x300,2);
  FUN_0041f3be(param_2,0x300,1,param_1);
  if ((param_1[3] & 0x20U) != 0) {
    FUN_0040187a((byte *)s__s__d____error_reading_00434c8c);
  }
  for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
    *(char *)(DAT_0043d760 + local_14 * 4) = param_2[local_14 * 3];
    *(char *)(DAT_0043d760 + 1 + local_14 * 4) = param_2[local_14 * 3 + 1];
    *(char *)(DAT_0043d760 + 2 + local_14 * 4) = param_2[local_14 * 3 + 2];
    if (local_14 == DAT_00434c50) {
      param_2[local_14 * 3] = (char)DAT_0043db60;
      *(char *)(DAT_0043d760 + local_14 * 4) = (char)DAT_0043db60;
      param_2[local_14 * 3 + 1] = (char)DAT_0043db64;
      *(char *)(DAT_0043d760 + 1 + local_14 * 4) = (char)DAT_0043db64;
      param_2[local_14 * 3 + 2] = (char)DAT_0043db68;
      *(char *)(DAT_0043d760 + 2 + local_14 * 4) = (char)DAT_0043db68;
      local_c = (uint)*(byte *)(DAT_0043d760 + local_14 * 4);
      local_10 = (uint)*(byte *)(DAT_0043d760 + 1 + local_14 * 4);
      local_8 = (uint)*(byte *)(DAT_0043d760 + 2 + local_14 * 4);
    }
  }
  if (DAT_00434c54 != 0) {
    for (local_14 = 0; local_14 < 0x100; local_14 = local_14 + 1) {
      if ((((local_14 != DAT_00434c50) && (local_c == *(byte *)(DAT_0043d760 + local_14 * 4))) &&
          (local_10 == *(byte *)(DAT_0043d760 + 1 + local_14 * 4))) &&
         (local_8 == *(byte *)(DAT_0043d760 + 2 + local_14 * 4))) {
        *(char *)(DAT_0043d760 + local_14 * 4) = (char)DAT_0043db60 + '\x01';
        param_2[local_14 * 3] = (char)DAT_0043db60 + '\x01';
      }
    }
  }
  return 0;
}

