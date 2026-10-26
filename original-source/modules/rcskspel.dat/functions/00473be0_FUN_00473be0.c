/*
 * FUN_00473be0 at 00473be0
 * undefined FUN_00473be0(void)
 * Address ranges: 00473be0-00473d33
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00473be0(undefined4 param_1)

{
  POINT pt;
  LONG *pLVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  BOOL BVar6;
  int iVar7;
  int *piVar8;
  int local_24;
  undefined1 local_1c [4];
  LONG local_18;
  LONG local_14;
  RECT local_10;
  
  FUN_004707f0();
  local_24 = -1;
  FUN_004b9ea0(&local_18,&local_14,local_1c);
  iVar7 = 0;
  if (DAT_004f7504 != -1) {
    piVar8 = &DAT_004f7504;
    do {
      pLVar1 = (LONG *)FUN_004715a0(*piVar8);
      local_10.left = *pLVar1;
      iVar2 = FUN_004715a0(*piVar8);
      local_10.top = *(LONG *)(iVar2 + 4);
      piVar3 = (int *)FUN_004715a0(*piVar8);
      piVar4 = (int *)FUN_00471560(*piVar8);
      local_10.right = *piVar4 + *piVar3;
      iVar2 = FUN_004715a0(*piVar8);
      iVar5 = FUN_00471560(*piVar8);
      local_10.bottom = *(int *)(iVar2 + 4) + *(int *)(iVar5 + 4);
      FUN_004afce0(s__d____d__d____d__d___pt__d__d__004f7604,iVar7,local_10.left,local_10.top,
                   local_10.right,local_10.bottom,local_18,local_14);
      pt.y = local_14;
      pt.x = local_18;
      BVar6 = PtInRect(&local_10,pt);
      if (BVar6 == 0) {
        FUN_004715e0(param_1,*piVar8,9);
      }
      else {
        FUN_004afce0(s___focus_to__d_004f7624,iVar7);
        FUN_004715e0(param_1,*piVar8 + 1,9);
        local_24 = *piVar8;
      }
      piVar3 = piVar8 + 1;
      piVar8 = piVar8 + 1;
      iVar7 = iVar7 + 1;
    } while (*piVar3 != -1);
    return local_24;
  }
  return -1;
}

