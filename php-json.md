## PHP JSON Example
```php
<?php

$json = array(
    'Name' => 'Amran',
    'Address' => array(
        'Present-address' => array(
            'Zilla' => 'dhaka',
            'Thana' => 'khilkhet'
        ),
        'Permanent-address' => array(
            'Zila' => 'gazipur',
            'Thana' => 'kaligonj'
        )
    ),
    'Aga' => 25,
    'Gender' => 'male',
    'Nick' => 'netcse'
);

$decode = json_encode($json);

$decoded = json_decode($decode);

echo $json['Address']['Present-address']['Thana'];
```



