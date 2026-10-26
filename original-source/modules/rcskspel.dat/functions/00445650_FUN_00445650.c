/*
 * FUN_00445650 at 00445650
 * undefined FUN_00445650(void)
 * Address ranges: 00445650-00445718
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

uint FUN_00445650(char *param_1)

{
  char cVar1;
  uint in_EAX;
  int iVar2;
  uint uVar3;
  
  if (*param_1 == '\0') {
    return in_EAX & 0xffffff00;
  }
  iVar2 = *(int *)(param_1 + 0x18);
  if ((iVar2 < 0) || (DAT_00543760 <= iVar2)) {
    FUN_004afee0(s__s___d__Path_does_not_exist__Pat_004ef418,
                 s_D__work_rcsk_Code_game_pth_main__004ef3f4,0x207,iVar2,DAT_00543760);
  }
  iVar2 = FUN_00444ba0(*(undefined4 *)(param_1 + 0x18));
  iVar2 = (&DAT_0053f668)[iVar2 * 0xd0];
  cVar1 = FUN_00446b80(iVar2);
  if (cVar1 == '\0') {
    if ((iVar2 < 0) || (0xd < iVar2)) {
      FUN_004afee0(s__s___d__Unknown_path_type__Path__004ef478,
                   s_D__work_rcsk_Code_game_pth_main__004ef454,0x215,*(undefined4 *)(param_1 + 0x18)
                   ,iVar2);
    }
    if ((&PTR_FUN_004ef050)[iVar2 * 5] == (undefined *)0x0) {
      FUN_004afee0(s__s___d__NULL_pointer_for_path_ha_004ef4d0,
                   s_D__work_rcsk_Code_game_pth_main__004ef4ac,0x21c,*(undefined4 *)(param_1 + 0x18)
                   ,iVar2);
    }
    uVar3 = (*(code *)(&PTR_FUN_004ef050)[iVar2 * 5])(param_1);
    return uVar3;
  }
  uVar3 = FUN_00446dd0(param_1);
  return uVar3;
}

