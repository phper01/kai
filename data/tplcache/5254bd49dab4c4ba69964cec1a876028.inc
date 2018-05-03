
                [field:pagestyle runphp='yes'] @me= (@me==3 ? '<li>' : '');[/field:pagestyle]
                <a [field:pagestyle runphp='yes'] @me= (@me==3 ? 'class="pic"' : ''); [/field:pagestyle]>
                  <img src='[field:imgsrc/]' id='bigimg' [field:imgwidth /] alt='[field:alttext /]' style="margin-top:-400px;" border='0' />
                </a>
                
                [field:pagestyle runphp='yes'] @me = (@me==3 ? '</li>' : ''); [/field:pagestyle]
             