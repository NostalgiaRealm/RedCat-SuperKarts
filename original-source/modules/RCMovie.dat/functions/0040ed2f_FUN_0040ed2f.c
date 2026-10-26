/*
 * FUN_0040ed2f at 0040ed2f
 * undefined4 __cdecl FUN_0040ed2f(int param_1)
 * Address ranges: 0040ed2f-0040eef5
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040ed2f(int param_1)

{
  UINT UVar1;
  int local_6c;
  CHAR local_68 [100];
  
  if (DAT_0043d7ec == 0) {
    DAT_0043d798 = LocalAlloc(0x40,param_1 << 3);
    if (DAT_0043d798 == (HLOCAL)0x0) {
      FUN_0040187a((byte *)s__s__d____error_not_enough_memory_00432cb0);
    }
    DAT_0043d79c = param_1;
    for (local_6c = 0; local_6c < param_1; local_6c = local_6c + 1) {
      FUN_0041fe16(local_68,&DAT_00432cec);
      *(int *)((int)DAT_0043d798 + local_6c * 8) = local_6c;
      UVar1 = GetDriveTypeA(local_68);
      switch(UVar1) {
      case 0:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 0;
        FUN_004015a6((byte *)s__s___UNAVAILABLE_00432cf4);
        break;
      case 1:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 0;
        FUN_004015a6((byte *)s__s___UNAVAILABLE_00432d08);
        break;
      case 2:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 1;
        FUN_004015a6((byte *)s__s___FLOPPY_00432d50);
        break;
      case 3:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 2;
        FUN_004015a6((byte *)s__s___HDD_00432d38);
        break;
      case 4:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 4;
        FUN_004015a6((byte *)s__s___NETWORK_00432d1c);
        break;
      case 5:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 3;
        FUN_004015a6((byte *)s__s___CDROM_00432d2c);
        break;
      case 6:
        *(undefined4 *)((int)DAT_0043d798 + local_6c * 8 + 4) = 5;
        FUN_004015a6((byte *)s__s___RAM_00432d44);
      }
    }
    DAT_0043d7ec = 1;
  }
  return 0;
}

