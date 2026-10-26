/*
 * FUN_0042fcb0 at 0042fcb0
 * undefined FUN_0042fcb0(void)
 * Address ranges: 0042fcb0-0042fd6e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042fcb0(int param_1,int *param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  code *pcVar6;
  
  FUN_00414b00(param_1,param_2);
  pcVar6 = FUN_0042fe80;
  puVar5 = &LAB_0042feb8;
  iVar3 = param_1;
  iVar4 = param_1;
  bVar1 = FUN_0042fc88();
  (**(code **)(*param_2 + 4))(param_2,"Height",bVar1,puVar5,iVar3,pcVar6,iVar4);
  pcVar6 = FUN_0042fe58;
  puVar5 = &LAB_0042fea0;
  iVar3 = param_1;
  iVar4 = param_1;
  uVar2 = FUN_0042fc20();
  (**(code **)(*param_2 + 4))(param_2,"HorizontalOffset",uVar2,puVar5,iVar3,pcVar6,iVar4);
  pcVar6 = FUN_0042fe6c;
  puVar5 = &LAB_0042feac;
  iVar3 = param_1;
  iVar4 = param_1;
  uVar2 = FUN_0042fc54();
  (**(code **)(*param_2 + 4))(param_2,"VerticalOffset",uVar2,puVar5,iVar3,pcVar6,iVar4);
  puVar5 = &LAB_0042fe44;
  pcVar6 = FUN_0042fe94;
  iVar3 = param_1;
  bVar1 = FUN_0042fbf8();
  (**(code **)(*param_2 + 4))(param_2,"Width",bVar1,pcVar6,param_1,puVar5,iVar3);
  return;
}

