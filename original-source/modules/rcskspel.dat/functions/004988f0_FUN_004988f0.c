/*
 * FUN_004988f0 at 004988f0
 * undefined FUN_004988f0(void)
 * Address ranges: 004988f0-00498940
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_004988f0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (((*(int *)(param_1 + 0x74) == 1) || (*(int *)(param_1 + 0x78) == 1)) ||
     (*(int *)(param_1 + 0x7c) == 1)) {
    FUN_004afee0(s__s__d____Cannot_set_orientation_i_004fb4d0,
                 s_D__work_rcsk_Code_Engine_Prog_ca_004fb4a4,0xbd,*(undefined4 *)(param_1 + 0x6c),
                 *(int *)(param_1 + 0x74),*(undefined4 *)(param_1 + 0x78),
                 *(undefined4 *)(param_1 + 0x7c));
  }
  puVar2 = (undefined4 *)(param_1 + 0x14);
  for (iVar1 = 0x10; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4), iVar1 != 0;
      iVar1 = iVar1 + -1) {
    *puVar2 = *(undefined4 *)register0x00000010;
    puVar2 = puVar2 + 1;
  }
  return;
}

