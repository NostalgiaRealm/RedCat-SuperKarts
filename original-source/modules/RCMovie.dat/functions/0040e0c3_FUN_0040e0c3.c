/*
 * FUN_0040e0c3 at 0040e0c3
 * undefined __cdecl FUN_0040e0c3(uint param_1, int param_2, short * param_3)
 * Address ranges: 0040e0c3-0040e320
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_0040e0c3(uint param_1,int param_2,short *param_3)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  uint uVar5;
  short local_14;
  byte bVar4;
  
  if (DAT_0043d720 == 0) {
    FUN_0040187a((byte *)s__s__d____error_please_use_get_xv_004326d8);
  }
  bVar3 = (byte)DAT_0043d74c;
  bVar4 = (byte)DAT_0043d750;
  if (param_2 == 8) {
    if (DAT_0042c358 == 8) {
      *(undefined1 *)param_3 = (undefined1)param_1;
    }
    else if (DAT_0042c358 == 0x10) {
      local_14 = (short)(((int)(uint)*(byte *)(DAT_0043d760 + param_1 * 4) >>
                         ((byte)DAT_0043d73c & 0x1f)) << ((byte)DAT_0043d748 & 0x1f)) +
                 (short)(((int)(uint)*(byte *)(DAT_0043d760 + 1 + param_1 * 4) >>
                         ((byte)DAT_0043d740 & 0x1f)) << (bVar3 & 0x1f)) +
                 (short)(((int)(uint)*(byte *)(DAT_0043d760 + 2 + param_1 * 4) >>
                         ((byte)DAT_0043d744 & 0x1f)) << (bVar4 & 0x1f));
      *param_3 = local_14;
    }
    else if (DAT_0042c358 == 0x18) {
      *(undefined1 *)(param_3 + 1) = *(undefined1 *)(DAT_0043d760 + param_1 * 4);
      *(undefined1 *)((int)param_3 + 1) = *(undefined1 *)(DAT_0043d760 + 1 + param_1 * 4);
      *(undefined1 *)param_3 = *(undefined1 *)(DAT_0043d760 + 2 + param_1 * 4);
    }
  }
  else if (param_2 == 0x10) {
    if (DAT_0042c358 == 8) {
      FUN_0040187a((byte *)s_not_yet_supported_00432710);
    }
    else if (DAT_0042c358 == 0x10) {
      *param_3 = (short)param_1;
    }
    else if (DAT_0042c358 == 0x18) {
      uVar1 = param_1 & _DAT_0043d734;
      uVar5 = param_1 & _DAT_0043d738;
      *(char *)(param_3 + 1) =
           (char)(((int)(param_1 & _DAT_0043d730) >> ((byte)DAT_0043d748 & 0x1f)) <<
                 ((byte)DAT_0043d73c & 0x1f));
      *(char *)((int)param_3 + 1) =
           (char)(((int)uVar1 >> (bVar3 & 0x1f)) << ((byte)DAT_0043d740 & 0x1f));
      *(char *)param_3 = (char)(((int)uVar5 >> (bVar4 & 0x1f)) << ((byte)DAT_0043d744 & 0x1f));
    }
  }
  else if (param_2 == 0x18) {
    if (DAT_0042c358 == 0x10) {
      iVar2 = FUN_0040dce3(param_1);
      *param_3 = (short)iVar2;
    }
    else {
      FUN_0040187a((byte *)s__s___d___Translation_from_24_bit_00432730);
    }
  }
  return;
}

