/*
 * FUN_00493860 at 00493860
 * undefined FUN_00493860(void)
 * Address ranges: 00493860-004938d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00493860(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1 * 0xd0;
  iVar1 = *(int *)(iVar2 + 0x24 + DAT_0067ee20);
  if ((iVar1 < 0) || (DAT_00680ae4 < iVar1)) {
    FUN_004afce0(s_Object_chunk____d__type____d_004fac2c,
                 *(undefined4 *)(iVar2 + 0x1c + DAT_0067ee20),*(undefined4 *)(iVar2 + DAT_0067ee20))
    ;
    FUN_004afee0(s___s___d_Illegal_waypoint___d__fo_004fabfc,
                 s_D__work_rcsk_Code_Engine_Prog_If_004faa80,0x20f,
                 *(undefined4 *)(iVar2 + 0x24 + DAT_0067ee20),param_1);
  }
  FUN_00494510(param_1);
  return;
}

