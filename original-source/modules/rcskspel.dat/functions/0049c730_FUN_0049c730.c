/*
 * FUN_0049c730 at 0049c730
 * undefined FUN_0049c730(void)
 * Address ranges: 0049c730-0049c7f8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_0049c730(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  FUN_004afce0(s_TXTCACHE_Adding_texture__d_004fbb90,param_2);
  if ((char)param_1[2] == '\0') {
    FUN_004afce0(s_Texture_cache_not_yet_filled_whi_004fbb64);
    return 0;
  }
  param_2 = param_2 * 0x48;
  iVar2 = *(int *)(param_2 + 0x24 + DAT_006a5e80);
  iVar3 = *(int *)(DAT_006a5e80 + 0x24 + *param_1 * 0x48);
  iVar1 = DAT_006a5e80 + *param_1 * 0x48;
  if ((iVar2 == iVar3) && (*(int *)(param_2 + 0x28 + DAT_006a5e80) == *(int *)(iVar1 + 0x28))) {
    *(undefined4 *)(param_2 + 8 + DAT_006a5e80) = *(undefined4 *)(iVar1 + 8);
    piVar4 = *(int **)(DAT_006a5e80 + 8 + *param_1 * 0x48);
    (**(code **)(*piVar4 + 4))(piVar4);
    *(undefined4 *)(param_2 + 0x10 + DAT_006a5e80) =
         *(undefined4 *)(DAT_006a5e80 + 0x10 + *param_1 * 0x48);
    piVar4 = *(int **)(param_2 + 0x10 + DAT_006a5e80);
    (**(code **)(*piVar4 + 4))(piVar4);
    *(undefined4 *)(param_2 + DAT_006a5e80) = *(undefined4 *)(DAT_006a5e80 + *param_1 * 0x48);
    return 1;
  }
  FUN_004afce0(s_Texture_cache_width___d__not_equ_004fbb28,iVar2,iVar3);
  return 0;
}

