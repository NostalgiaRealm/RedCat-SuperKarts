/*
 * FUN_00464288 at 00464288
 * undefined __register FUN_00464288(int * param_1)
 * Address ranges: 00464288-00464337
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00464288(int *param_1)

{
  char cVar1;
  undefined4 *in_FS_OFFSET;
  undefined1 auStackY_100 [172];
  undefined4 uStackY_54;
  undefined1 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  char cVar6;
  byte bVar7;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  undefined1 *puStack_2c;
  undefined *local_20;
  tagRECT local_1c;
  int local_c;
  undefined4 local_8;
  
  puStack_2c = &stack0xfffffffc;
  local_20 = (undefined *)0x0;
  puStack_30 = &LAB_00464338;
  uStack_34 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_34;
  FUN_00463ecc(param_1,&local_1c);
  FUN_00417bbc(*(int **)(param_1[0x83] + 0x10),0x80000008);
  (**(code **)(**(int **)(param_1[0x83] + 0xc) + 8))(*(int **)(param_1[0x83] + 0xc),param_1[0x16]);
  bVar7 = 0;
  cVar1 = (**(code **)(*param_1 + 0x4c))();
  if (cVar1 == '\0') {
    bVar7 = 2;
  }
  local_c = *(int *)(param_1[0x80] + 0xc);
  local_8 = *(undefined4 *)(param_1[0x80] + 0x10);
  cVar6 = '\0';
  cVar1 = '\x01';
  piVar5 = &local_c;
  piVar4 = (int *)0x0;
  iVar3 = 0;
  puVar2 = auStackY_100;
  uStackY_54 = 0x464311;
  FUN_0043f64c((int)param_1,(int *)&local_20);
  uStackY_54 = 0x464322;
  FUN_0044efe4((int *)param_1[0x83],&local_1c.left,local_20,(uint)puVar2,iVar3,piVar4,piVar5,cVar1,
               cVar6,bVar7);
  *in_FS_OFFSET = puVar2;
  FUN_00403b50((int *)&local_20);
  return;
}

