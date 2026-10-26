/*
 * FUN_0045aa8c at 0045aa8c
 * undefined __register FUN_0045aa8c(uint param_1)
 * Address ranges: 0045aa8c-0045abfd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045aa8c(uint param_1)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_ECX;
  byte *unaff_ESI;
  int *in_FS_OFFSET;
  undefined1 uVar6;
  int *piVar7;
  uint *local_30;
  uint *local_2c;
  int local_28;
  undefined1 *local_24;
  undefined4 *local_20;
  int iVar8;
  int local_10;
  byte *local_c;
  int local_8;
  
  local_20 = (undefined4 *)&stack0xfffffffc;
  local_10 = 5;
  do {
    local_8 = 0;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  local_24 = &LAB_0045abfe;
  local_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = (int)&local_28;
  local_2c = (uint *)0x45aac4;
  FUN_00403be8((int *)&local_c,*(int *)(PTR_PTR_0047c5e0 + (param_1 & 0xff) * 4));
  local_2c = (uint *)0x45aad3;
  FUN_0043285c(*(undefined4 *)PTR_DAT_0047c86c,(int *)&local_24);
  local_2c = (uint *)0x45aade;
  FUN_004081c4(local_24,(int *)&local_20);
  local_2c = (uint *)0x45aaeb;
  FUN_00403dd8((int *)&local_20,(undefined4 *)"game.ini");
  local_2c = (uint *)0x45aafa;
  piVar2 = FUN_0044f4ac((int *)&PTR_FUN_0044f450,'\x01',local_20);
  local_2c = (uint *)0x45ab08;
  piVar3 = FUN_00454494((int *)&LAB_00454484,'\x01',extraout_ECX);
  local_2c = (uint *)0x0;
  local_30 = (uint *)0x45ab1e;
  iVar4 = (**(code **)(*piVar2 + 8))(piVar2,"AVAILABLE_CHARACTERS","count");
  local_8 = -1;
  if ((0 < iVar4) && (-1 < iVar4 + -1)) {
    iVar8 = 0;
    do {
      local_30 = (uint *)0x0;
      piVar7 = &local_10;
      FUN_00407f60(iVar8,&local_28);
      (**(code **)*piVar2)(piVar2,"AVAILABLE_CHARACTERS",local_28,piVar7);
      if (local_10 != 0) {
        local_30 = (uint *)0x45ab75;
        FUN_00454510((int)piVar3,local_10);
        local_30 = (uint *)0x45ab82;
        FUN_0045471c((int)piVar3,0,(int *)&stack0xffffffe8);
        local_30 = (uint *)0x45ab8a;
        iVar5 = FUN_00403dd0((int)unaff_ESI);
        uVar6 = iVar5 == 0;
        if (0 < iVar5) {
          local_30 = (uint *)0x45ab99;
          FUN_00407ca8(unaff_ESI,(int *)&local_2c);
          local_30 = local_2c;
          FUN_00407ca8(local_c,(int *)&local_30);
          puVar1 = local_30;
          local_30 = (uint *)0x45abb1;
          FUN_00403ee0(puVar1,puVar1);
          if ((bool)uVar6) {
            local_8 = iVar8;
          }
        }
      }
      iVar8 = iVar8 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  local_30 = (uint *)0x45abc7;
  FUN_00402eac(piVar3);
  local_30 = (uint *)0x45abce;
  FUN_00402eac(piVar2);
  *in_FS_OFFSET = (int)local_2c;
  local_24 = &LAB_0045ac05;
  local_28 = 0x45abe8;
  FUN_00403b74((int *)&local_30,5);
  local_28 = 0x45abf0;
  FUN_00403b50((int *)&stack0xffffffe8);
  local_28 = 0x45abfd;
  FUN_00403b74(&local_10,2);
  return;
}

