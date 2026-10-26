/*
 * FUN_0044cd70 at 0044cd70
 * undefined __register FUN_0044cd70(int param_1, int param_2, undefined * param_3)
 * Address ranges: 0044cd70-0044ce89
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0044cd70(int param_1,int param_2,undefined *param_3)

{
  HMODULE hModule;
  HRSRC hResInfo;
  undefined4 uVar1;
  HGLOBAL pvVar2;
  undefined4 *in_FS_OFFSET;
  undefined **ppuVar3;
  undefined1 *puStack_130;
  undefined1 *puStack_12c;
  undefined1 *puStack_128;
  byte *local_118;
  byte *local_114;
  undefined *local_110;
  undefined1 local_10c;
  char local_108 [256];
  undefined *local_8;
  
  puStack_128 = &stack0xfffffffc;
  local_118 = (byte *)0x0;
  local_114 = (byte *)0x0;
  puStack_12c = &LAB_0044ce8a;
  puStack_130 = (undefined1 *)*in_FS_OFFSET;
  *in_FS_OFFSET = &puStack_130;
  local_8 = param_3;
  FUN_00408428(local_108,param_3,0xff);
  hModule = (HMODULE)FUN_00404ef0(param_2);
  hResInfo = FindResourceA(hModule,local_108,(LPCSTR)0xa);
  if (hResInfo == (HRSRC)0x0) {
    local_110 = local_8;
    local_10c = 0xb;
    ppuVar3 = &local_110;
    hModule = (HMODULE)0x0;
    FUN_0044cb68(DAT_0047d868,3,(int *)&local_114);
    uVar1 = FUN_0040aca0((int)&DAT_0044ca4c,'\x01',local_114,hModule,ppuVar3);
    FUN_00403604(uVar1);
  }
  else {
    pvVar2 = LoadResource(hModule,hResInfo);
    *(HGLOBAL *)(param_1 + 8) = pvVar2;
    if (*(int *)(param_1 + 8) == 0) {
      local_110 = local_8;
      local_10c = 0xb;
      ppuVar3 = &local_110;
      hModule = (HMODULE)0x0;
      FUN_0044cb68(DAT_0047d868,4,(int *)&local_118);
      uVar1 = FUN_0040aca0((int)&DAT_0044ca4c,'\x01',local_118,hModule,ppuVar3);
      FUN_00403604(uVar1);
    }
  }
  *in_FS_OFFSET = hModule;
  puStack_130 = &LAB_0044ce91;
  FUN_00403b74((int *)&local_118,2);
  return;
}

