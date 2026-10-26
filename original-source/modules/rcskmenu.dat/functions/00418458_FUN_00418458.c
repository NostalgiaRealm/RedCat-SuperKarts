/*
 * FUN_00418458 at 00418458
 * undefined __register FUN_00418458(int * param_1, int param_2, int param_3, int * param_4)
 * Address ranges: 00418458-004184fd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418458(int *param_1,int param_2,int param_3,int *param_4)

{
  char cVar1;
  uint uVar2;
  COLORREF CVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_18 [4];
  int local_8;
  
  if (param_4 != (int *)0x0) {
    local_8 = param_3;
    cVar1 = (**(code **)(*param_4 + 0x1c))();
    if (cVar1 == '\0') {
      (**(code **)(*param_1 + 0x10))();
      FUN_00418a68(param_1,1);
      uVar2 = FUN_00417e98(param_1[5]);
      CVar3 = FUN_00417210(uVar2);
      SetBkColor((HDC)param_1[1],CVar3);
      CVar3 = FUN_00417210(*(uint *)(param_1[3] + 0x18));
      SetTextColor((HDC)param_1[1],CVar3);
      iVar4 = (**(code **)(*param_4 + 0x20))();
      iVar4 = iVar4 + local_8;
      puVar6 = local_18;
      iVar5 = (**(code **)(*param_4 + 0x2c))();
      FUN_0040ebe8(param_2,local_8,iVar5 + param_2,puVar6,iVar4);
      (**(code **)(*param_4 + 0x14))(param_4,param_1,local_18);
      (**(code **)(*param_1 + 0xc))();
    }
  }
  return;
}

