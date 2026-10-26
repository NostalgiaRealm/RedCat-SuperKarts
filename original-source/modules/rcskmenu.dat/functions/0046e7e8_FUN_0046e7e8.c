/*
 * FUN_0046e7e8 at 0046e7e8
 * undefined __register FUN_0046e7e8(int param_1)
 * Address ranges: 0046e7e8-0046e95c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e7e8(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  int iVar4;
  undefined4 *unaff_ESI;
  undefined *unaff_EDI;
  undefined4 *in_FS_OFFSET;
  int *piVar5;
  undefined4 uVar6;
  undefined4 *local_28;
  undefined4 *local_24;
  undefined1 *local_20;
  int local_10;
  int *local_c;
  int local_8;
  
  local_20 = &stack0xfffffffc;
  local_10 = 4;
  do {
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  local_24 = (undefined4 *)&LAB_0046e95d;
  local_28 = (undefined4 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &local_28;
  local_8 = param_1;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&stack0xffffffe4);
  FUN_004081c4(unaff_EDI,(int *)&stack0xffffffe8);
  FUN_00403dd8((int *)&stack0xffffffe8,(undefined4 *)"game.ini");
  local_c = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',unaff_ESI);
  piVar1 = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  iVar2 = (**(code **)(*local_c + 8))(local_c,"AVAILABLE_CHARACTERS","count");
  if ((0 < iVar2) && (-1 < iVar2 + -1)) {
    iVar4 = 0;
    do {
      uVar6 = 0;
      piVar5 = &local_10;
      FUN_00407f60(iVar4,(int *)&local_20);
      (**(code **)*local_c)(local_c,"AVAILABLE_CHARACTERS",local_20,piVar5,uVar6);
      iVar3 = FUN_00403dd0(local_10);
      if (0 < iVar3) {
        FUN_00454510((int)piVar1,local_10);
        *(int *)(local_8 + 4 + iVar4 * 0x14) = iVar4;
        FUN_0045471c((int)piVar1,0,(int *)&local_24);
        FUN_00403ba4((int *)(local_8 + 8 + iVar4 * 0x14),local_24);
        FUN_0045471c((int)piVar1,1,(int *)&local_28);
        FUN_00403ba4((int *)(local_8 + 0xc + iVar4 * 0x14),local_28);
        uVar6 = FUN_004546b4((int)piVar1,2);
        *(undefined4 *)(local_8 + 0x10 + iVar4 * 0x14) = uVar6;
        uVar6 = FUN_004546b4((int)piVar1,3);
        *(undefined4 *)(local_8 + 0x14 + iVar4 * 0x14) = uVar6;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  FUN_00402eac(local_c);
  FUN_00402eac(piVar1);
  *in_FS_OFFSET = 0;
  local_24 = (undefined4 *)&LAB_0046e964;
  local_28 = (undefined4 *)0x46e954;
  FUN_00403b74((int *)&local_28,5);
  local_28 = (undefined4 *)0x46e95c;
  FUN_00403b50(&local_10);
  return;
}

