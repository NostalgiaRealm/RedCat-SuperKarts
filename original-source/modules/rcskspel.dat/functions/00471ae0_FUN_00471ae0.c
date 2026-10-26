/*
 * FUN_00471ae0 at 00471ae0
 * undefined FUN_00471ae0(void)
 * Address ranges: 00471ae0-00471b74
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00471ae0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_3;
  iVar1 = param_2;
  DAT_00544bb8 = param_1;
  DAT_00544ba8 = param_2;
  DAT_00544ba4 = param_3;
  FUN_004b9ea0(&DAT_00544bb0,&DAT_00544bac,&param_1);
  if (DAT_00544bb4 == 0) {
    DAT_00544bb4 = FUN_004b0900(0x40,0x40);
    if (DAT_00544bb4 == 0) {
      FUN_004afee0(s__s__d____Couldn_t_create_mouse_s_004f6bac);
    }
  }
  FUN_004b6ec0(DAT_006a64c0,DAT_00544bb4,DAT_00544bb0,DAT_00544bac,iVar1 + DAT_00544bb0,
               DAT_00544bac + iVar2,0,0,iVar1,iVar2,3);
  return;
}

