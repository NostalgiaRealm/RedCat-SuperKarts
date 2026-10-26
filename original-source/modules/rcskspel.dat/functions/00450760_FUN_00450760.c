/*
 * FUN_00450760 at 00450760
 * undefined FUN_00450760(void)
 * Address ranges: 00450760-00450898
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_00450760(int param_1,int param_2)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_20;
  int local_1c;
  int local_18;
  undefined1 local_14 [8];
  int local_c;
  int local_8;
  int local_4;
  
  iVar3 = param_2;
  local_20 = 0;
  local_1c = param_1;
  if (0 < DAT_00680b2c) {
    do {
      bVar2 = false;
      iVar6 = 0;
      param_2 = *(int *)(DAT_00680b28 + 0xe8 + local_20 * 0x984);
      if (0 < param_2) {
        do {
          iVar1 = *(int *)(DAT_00680b28 + 0x154 + (iVar6 + local_20 * 0x261) * 4);
          iVar4 = FUN_0040d720(*(undefined4 *)(iVar1 * 0x50 + 4 + DAT_00680ae0));
          if (iVar3 == iVar4) {
            local_4 = iVar3;
            local_c = local_20;
            bVar2 = true;
            local_8 = iVar1;
            FUN_004533c0(*(undefined4 *)(*(int *)(local_1c + 4) + 8),1,&local_c);
          }
          iVar1 = local_1c;
          iVar6 = iVar6 + 1;
        } while (iVar6 < param_2);
        if (bVar2) {
          iVar6 = *(int *)(local_1c + 0xc);
          param_2 = FUN_004530c0(&local_20);
          if ((param_2 == *(int *)(iVar1 + 0xc)) || (local_20 < *(int *)(param_2 + 0xc))) {
            local_18 = *(int *)(iVar1 + 0xc);
            piVar5 = &local_18;
          }
          else {
            piVar5 = &param_2;
          }
          if (*piVar5 != iVar6) {
            FUN_004afce0(s___Bonuses_on_chunk__d_004f122c,iVar3,local_20);
            FUN_00452780(local_14,&local_20);
          }
        }
      }
      local_20 = local_20 + 1;
    } while (local_20 < DAT_00680b2c);
  }
  return;
}

