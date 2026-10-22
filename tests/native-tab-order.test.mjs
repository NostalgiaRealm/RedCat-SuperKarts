import test from 'node:test';
import assert from 'node:assert/strict';
import fs from 'node:fs';
import {nativeFormTabOrder,nativeNavigationOrder,nativeOrderedChildren} from '../src/native-tab-order.js';
const forms=JSON.parse(fs.readFileSync(new URL('../public/assets/ui/forms.json',import.meta.url)));
const fixtures=JSON.parse(fs.readFileSync(new URL('../evidence/native/tab-order-fixtures.json',import.meta.url)));
function find(item,name){return item.name===name?item:item.children.map(child=>find(child,name)).find(Boolean);}
const ordered=name=>[...nativeFormTabOrder(forms[name])].filter(([,rank])=>rank>=0).map(([name])=>name);
test('original DFM main and control TabOrder differs from serialized element order',()=>{
  assert.deepEqual(ordered('TFRMMAIN'),['btnAdventure','btnQuickRace','btnHighscore','btnMainOptions','btnMainHelp','btnMainStop']);
  assert.deepEqual(ordered('TFRMCONTROLSETTINGS'),['btnDefault','btnCancel','btnHelp','btnOk','chkShowInfo']);
});
test('native Options traversal respects nested transparent-control TabOrder',()=>{
  assert.deepEqual(ordered('TFRMOPTIONS'),['btnMainStop','btnMainHelp','btnBack','btnOk','sldMusicVolume','sldEffectVolume',
    'rdoLowQual','rdoHighQual','chk3dCard','btnAdvanced','rdoKeyboard','rdoJoystick','rdoGamepad','btnControlsAdvanced','chkStartInfo']);
});
test('directional navigation shares native ordering and retains additional accessible elements',()=>{
  const elements=[5,1,undefined,3].map(order=>({dataset:{nativeTabOrder:order}}));
  assert.deepEqual(nativeNavigationOrder(elements),[elements[1],elements[3],elements[0],elements[2]]);
});
test('29 shipped sibling lists match original Loaded and SetTabOrder instructions',()=>{
  for(const row of fixtures.cases)
    assert.deepEqual(nativeOrderedChildren(find(forms[row.form],row.parent)).map(child=>child.name),row.output);
});
