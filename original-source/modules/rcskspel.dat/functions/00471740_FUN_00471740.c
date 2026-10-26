/*
 * FUN_00471740 at 00471740
 * undefined FUN_00471740(void)
 * Address ranges: 00471740-00471818
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00471740(void)

{
  char cVar1;
  undefined3 uVar3;
  undefined1 *puVar2;
  undefined3 extraout_var;
  int iVar4;
  char *pcVar5;
  undefined1 local_11c [4];
  undefined1 *local_118;
  char local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d08d6;
  local_c = ExceptionList;
  uVar3 = (undefined3)((uint)ExceptionList >> 8);
  if (DAT_00544ba0 == '\0') {
    ExceptionList = &local_c;
    FUN_004b1d60(s_SndGfx_ini_004f69cc);
    FUN_00470610(local_11c,0);
    local_4 = 0;
    local_10c[0] = '\0';
    puVar2 = local_118;
    if (local_118 == (undefined1 *)0x0) {
      puVar2 = &DAT_004d2404;
    }
    FUN_004b1f10(s_STOPPEN_004f69d8,puVar2,local_10c,0x100);
    iVar4 = -1;
    pcVar5 = local_10c;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    DAT_00544ba1 = iVar4 != -2;
    DAT_00544ba0 = '\x01';
    if (local_118 == (undefined1 *)0x0) {
      DAT_00544ba0 = 1;
      ExceptionList = local_c;
      return (uint)(byte)DAT_00544ba1;
    }
    cVar1 = local_118[-1];
    if ((cVar1 == '\0') || (cVar1 == -1)) {
      FUN_004bc150(local_118 + -1);
      uVar3 = extraout_var;
    }
    else {
      uVar3 = 0;
      local_118[-1] = cVar1 + -1;
    }
  }
  ExceptionList = local_c;
  return CONCAT31(uVar3,DAT_00544ba1);
}

