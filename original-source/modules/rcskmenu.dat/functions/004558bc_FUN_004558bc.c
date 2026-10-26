/*
 * FUN_004558bc at 004558bc
 * undefined FUN_004558bc(void)
 * Address ranges: 004558bc-004558fc
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004558bc(undefined4 param_1,int param_2,undefined4 param_3)

{
  char *pcVar1;
  undefined4 uVar2;
  char unaff_BL;
  short unaff_BP;
  undefined1 *unaff_ESI;
  undefined2 in_SS;
  undefined4 *in_FS_OFFSET;
  undefined1 auStack_18 [16];
  undefined4 uStack_4;
  
  pcVar1 = (char *)(CONCAT31((int3)((uint)param_1 >> 8),0x57) + -0x63ffbaaf);
  *pcVar1 = *pcVar1 + unaff_BL;
  uStack_4 = param_3;
  pcVar1 = (char *)((int)&uStack_4 + param_2 * 2);
  *pcVar1 = *pcVar1 + (char)param_3;
  out(*unaff_ESI,(short)param_2);
  segment(in_SS,unaff_BP + 0x67);
  uVar2 = *in_FS_OFFSET;
  *in_FS_OFFSET = auStack_18;
  _DAT_0047d92c = _DAT_0047d92c + 1;
  *in_FS_OFFSET = uVar2;
  return;
}

